import java.util.Scanner;
public class A3_Q4 {

	public static void main(String[] args) {
		Scanner c = new Scanner(System.in);
		
		System.out.print("Enter any Character : ");
		char ch = c.next().charAt(0);
		
		int q = ch;
		
		if(q>=65&&q<=90) {
			System.out.print("Capital Letter");
		}
		else if(q>=97 && q<=122) {
			System.out.print("small case Letter");
		}
		else if(q>=48 && q<=57) {
			System.out.print("It's a Digit");
		}
		else if(q>=0 && q<=47 || q>=58 && q<=64 || q>=91 && q<=96 || q>=123 && q<=127) {
			System.out.print("Symbol");
		}
		else {
			System.out.print("Invalid");
		}
	}

}
