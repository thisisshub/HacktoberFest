//Java Program to check whether a number is palindrome or not

import java.util.Scanner;

public class Palindrome {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter A Number :");
		int number = sc.nextInt();
		
		int org,res=0,rem;
		
		org=number;
		while(org!=0) {
			rem=org%10;
			res=(res*10)+rem;
			org/=10;
		}
		System.out.println(res);
		
		if(number==res) {
			System.out.println(number+" is a Palindrome Number");
		}
		else {
			System.out.println(number+" is not Palindrome Number");
		}
	}
}
