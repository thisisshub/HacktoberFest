// function that checks if the number is prime or not

const PrimeCheck = (n) => {
  // input: n: int
  // output: boolean
  if (n === 1) return false
  if (n === 0) return false

  for (let i = 2; i * i <= n; i++) {
    if (n % i === 0) {
      return false
    }
  }
  return true
}
//test
console.log(PrimeCheck(5))