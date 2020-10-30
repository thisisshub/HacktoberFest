import java.util.Scanner;

public class A3_Q8 {

	public static void main(String[] args) {
		
		Scanner age = new Scanner(System.in);
		System.out.print("Enter the ages of Rahul,Ajay and Ayush : ");
		
		int Rahul = age.nextInt();
		int Ajay = age.nextInt();
		int Ayush = age.nextInt();
		
		if(Rahul>Ajay && Rahul>Ayush) {
			System.out.print("Rahul is Elder.");
		}
		else if(Ajay>Ayush) {
			System.out.print("Ajay is Elder.");
		}
		else {
			System.out.print("Ayush is Elder.");
		}

	}

}
