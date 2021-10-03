/**
 * 
 * @param {*} promiseArray 
 * @returns single promise that fulfills when all of the promises passed as an iterable has been filfilled or rejects with the reason for the first promise which rejects
 */

export function promiseAll(promiseArray) {
  var output = new Array(promiseArray.length);
  var counter = 0;

  return new Promise((resolve, reject) => {
    promiseArray.forEach((promise, index) => {
      Promise.resolve(promise)
        .then(value => {
          output[index] = value;
          counter += 1;
          // if all promises are resolved, resolve outer promise
          if (counter == promiseArray.length) {
            resolve(output);
          }
        })
        .catch(reject);
    })
  })
}

/**
 * 
 * @param {*} promiseArray 
 * @returns first promise that fulfils or rejects
 */
export function promiseRace(promiseArray) {
  return new Promise((resolve, reject) => {
    promiseArray.forEach(promise => {
      Promise.resolve(promise)
        .then(resolve)
        .catch(reject);
    })
  })
}

/**
 * 
 * @param {*} promiseArray 
 * @returns a promise which resolves after all of the given promises have either been resolved or rejected, with an array of objects that each describes the outcome of each promise.
 */
export function promiseAllSettled(promiseArray) {
  var wrappedPromiseArray = promiseArray.map(
    promise => Promise.resolve(promise)
      .then(value => ({ status: 'fulfilled', value }))
      .catch(reason => ({ status: 'rejected', reason }))
  );
  return promiseAll(wrappedPromiseArray);
}

/**
 * 
 * @param {*} promiseArray 
 * @returns a single promise that resolves with the value from that promise as soon as it is resolved. If no promise in the iterable is resolved then returned promise is rejected with an array of rejection errors.
 */
export function promiseAny(promiseArray) {
  var errorOutput = new Array(promiseArray.length);
  var counter = 0;

  return new Promise((resolve, reject) => {
    promiseArray.forEach((promise, index) => {
      Promise.resolve(promise)
        .then(resolve)
        .catch(error => {
          errorOutput[index] = error;
          counter = counter + 1;
          if (counter == promiseArray.length) {
            reject(errorOutput);
          }
        })
    })
  })
}



