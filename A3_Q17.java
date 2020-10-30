import java.util.Scanner;
public class A3_Q17 {

	public static void main(String[] args) {
		Scanner n = new Scanner(System.in);
		System.out.print("Enter an Integer : ");
		int a = n.nextInt();
		
		switch(1) {
		
		case 1:
			boolean b = (a%5==0 && a%6==0); 
			System.out.println("Is divisible by 5 and 6? " + b);
			

		case 2:
			boolean c = (a%5==0 || a%6==0); 
			System.out.println("Is divisible by 5 or 6? " + c);
			

		case 3:
			boolean d = (a%5==0 && a%6!=0 || a%5!=0 && a%6==0); 
			System.out.println("Is divisible by 5 or 6,but not both? " + d);
		}

	}

}
