// Author Ashhar Farooqui

import java.util.Scanner;

public class Largest {
	private static Scanner sc;
	public static void main(String[] args) 
	{
		int num1, num2, largest;
		sc = new Scanner(System.in);
		
		System.out.print(" Please Enter the First Number : ");
		num1 = sc.nextInt();	
		
		System.out.print(" Please Enter the Second Number : ");
		num2 = sc.nextInt();	
		
		if(num1 == num2) 
	    {
			System.out.println("\n Both are Equal");     
	    }
		else
		{
			largest = (num1 > num2)? num1: num2;
			System.out.println("\n The Largest Number = " + largest);   
		}
	}	
}

        
	












