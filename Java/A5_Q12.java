import java.util.Scanner;
public class A5_Q12 {

	public static void main(String[] args) {
		
		Scanner a=new Scanner(System.in);
		
		System.out.print("Enter value of x : ");
		int x = a.nextInt();
		System.out.print("Enter values of n : ");
		int n = a.nextInt();
		double sum = 0;
		int f = 1;
		for(int i = 1;i<=n;i++) {
			
			f*=i;
			
			sum += (Math.pow(x, i)/f);
			
			
		}
		
		System.out.println("Sum of Taylor Series : "+ (sum+1));

	}

}
