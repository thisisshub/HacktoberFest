/*
 * function that checks if a number is odd
 * return true if number is odd
 * else false
 */

const isOdd = (value) => {
  return !!((value & 1))
}

// testing
console.log(isOdd(2))
console.log(isOdd(3))
