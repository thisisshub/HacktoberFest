//program to find check armstrong or not 

let sum = 0;
const number = 321;   //No that you want to check 

// Temp variable to store that no
let temp = number;
while (temp > 0) {
    // finding the one's digit
    let remainder = temp % 10;

    sum =sum+( remainder * remainder * remainder);

    // removing last digit from the number
    temp = Math.floor(temp / 10); // convert float into integer
}
// check the condition
if (sum == number) {
    console.log("No is an Armstrong number`);
}
else {
    console.log(" No  is not an Armstrong number.");
}
