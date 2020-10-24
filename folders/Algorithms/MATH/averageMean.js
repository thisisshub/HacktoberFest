'use strict'
/*
    This script will find the average (mean) of an array of numbers.
*/

const mean = (nums) => {
  // This is a function returns average/mean of array
  let sum = 0

  // This loop sums all values in the 'nums' array using forEach loop
  nums.forEach(function (current) {
    sum += current
  })

  // Divide sum by the length of the 'nums' array.
  const avg = sum / nums.length
  return avg
}

export { mean }
