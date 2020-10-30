import java.util.Scanner;
public class A5_Q16 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		System.out.print("Enter digits to reverse : ");
		int n = s.nextInt();
		int p=0;
		while(n>0) {
			System.out.print(n%10);
			n/=10;
			
		}
		
		
		
		

	}

}
