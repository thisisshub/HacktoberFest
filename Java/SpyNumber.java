/*
 * A positive integer is called a spy number if the sum 
 * and product of its digits are equal. In other words, 
 * a number whose sum and product of all digits are 
 * equal is called a spy number.
 */


import java.util.Scanner;

public class SpyNumber {

    public static boolean IsSpy(int num) {
        int sum = 0, product = 1, digit;

        while (num > 0) {
            digit = num % 10;
            sum += digit;
            product *= digit;
            num /= 10;
        }

        if (sum == product) {
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        try {
            System.out.print("Enter number : ");
            int num = sc.nextInt();

            if(IsSpy(num))
                System.out.println(num + " is Spy number.");
            else
                System.out.println(num + " is not Spy number.");
        } finally {
            sc.close();
        }
    }
}