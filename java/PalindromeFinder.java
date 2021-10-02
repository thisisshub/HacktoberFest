public class PalindromeFinder {

    public static int reverseNumber(int number){ //method for reversing a number
        int reversedNumber = 0;
        while(number != 0){
            int digit = number % 10;
            reversedNumber = reversedNumber * 10 + digit;
            number /= 10;
        }
        return reversedNumber;
    }
    public static void main(String[] args){
        int num = 0;
        int reversedNum = reverseNumber(num);
        boolean palindrome = false;

        if(num == reversedNum){ palindrome = true; } //If the given number is the same as it's reverse, then it is a palindrome

        System.out.println(palindrome);
    }
}
