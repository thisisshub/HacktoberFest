import java.util.Scanner;
public class A3_Q6 {

	public static void main(String[] args) {
		Scanner n = new Scanner(System.in);
		System.out.print("ENter Values of a,b,c,d,e,f : ");
		double a = n.nextDouble();
		double b = n.nextDouble();
		double c = n.nextDouble();
		double d = n.nextDouble();
		double e = n.nextDouble();
		double f = n.nextDouble();
		
		double x = ((e*d) - (b*f))/((a*d)-(b*c));
		double y = ((a*f) - (e*c))/((a*d)-(b*c));
		if(((a*d)-(b*c))==0) {
			System.out.println("The equation has no solution.");
		}
		else {
			System.out.println("x is " + x + "\n"+ "y is " + y);
		}
		
	}

}
