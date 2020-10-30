import java.util.Scanner;

public class A3_Q18 {

	public static void main(String[] args) {
		Scanner n = new Scanner(System.in);
		System.out.print("What is your gender (M or F) : ");
		char gender = n.next().charAt(0);
		System.out.print("First Name : ");
		String fname = n.next();
		System.out.print("Last Name : ");
		String lname = n.next();
		System.out.print("Age : ");
		byte age = n.nextByte();
		if(age>=20 && (gender == 'F' || gender == 'M')) {
			System.out.print("Are you Married, "+fname + " (y or n) ");
			char yn = n.next().charAt(0);
				if(yn=='y' && gender=='F') {
				System.out.print("Then I shall call you Mrs. "+fname + " "+ lname);			
				}
				else if(yn=='n' && gender=='F'){
					System.out.print("Then I shall call you Ms. "+fname + " "+ lname);			
	
				}
				else if(yn=='y' && gender=='M') {
					System.out.print("Then I shall call you Mr. "+fname + " "+ lname);			
					}
				else {
					System.out.print("Then I shall call you "+fname + " "+ lname);			

				}
					
		}
		
		
		
		
		
		

	}

}
