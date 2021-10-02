//Java Program to find largest of 3 numbers and largest of 2 numbers using method overloading
import java.util.Scanner;

public class LargestOf {
	public void largestOf(int x,int y){
		if (x>y) {
			System.out.println(x+" is largest");
		}
		else if(x==y) {
			System.out.println(x+" = "+y);
		}
		else {
			System.out.println(y+" is largest");
		}
	}
	public void largestOf(int x,int y,int z) {
		if (x>y && x>z) {
			System.out.println(x+" is largest");
		}
		else if(y>z) {
			System.out.println(y+" is largest");
		}
		else {
			System.out.println(z+" is largest");
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		LargestOf ob1 = new LargestOf();
		int ch = 0;
		while (ch!=3) {
			System.out.println("Enter a choice :");
			System.out.println("1.Largest of 2 Numbers");
			System.out.println("2.Largest of 3 Numbers");
			System.out.println("3.Exit");
			ch = sc.nextInt();
			switch (ch) {
			case 1:
				System.out.println("Enter first no:");
				int a = sc.nextInt();
				System.out.println("Enter second no:");
				int b = sc.nextInt();
				ob1.largestOf(a, b);
				break;
			case 2:
				System.out.println("Enter first no:");
				int a1 = sc.nextInt();
				System.out.println("Enter second no:");
				int b1 = sc.nextInt();
				System.out.println("Enter third no:");
				int c1 = sc.nextInt();
				ob1.largestOf(a1, b1, c1);
				break;
			case 3:
				return;
			

			default:
				System.out.println("Enter correct choice");
				break;
			}
		}
		
	}
}
