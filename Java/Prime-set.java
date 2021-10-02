//Write a java program to find the prime numbers in a set of numbers .The size of the set should be passed as argument of constructor

import java.util.Scanner;

public class PrimeSet {
	Scanner sc = new Scanner(System.in);

	public PrimeSet(int limit) {
		int arr[] = new int[limit];
		System.out.println("Enter Elements :");
		for (int i = 0; i < arr.length; i++) {
			arr[i]=sc.nextInt();
		}
		System.out.println("Prime Numbers in given set :");

		for (int i = 0; i < arr.length; i++) {
			boolean isPrime=true;
			for (int j = 2; j <= arr[i]/2; j++) {
				if (arr[i]%j==0) {
					isPrime=false;
					break;
				}
			}
			if (isPrime) {
				System.out.print(arr[i]+" ");
			}
		}
	}	
	
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter no. of elements :"); 
		int n = sc.nextInt();
		new PrimeSet(n);
		
	}
