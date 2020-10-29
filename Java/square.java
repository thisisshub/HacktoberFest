import java.util.scanner;
public class Square
{
public static void main(String args[])
{
Scanner scan=new Scanner(System.in);
int num;
System.out.print("Enter an integer number: ");
num=scan.nextInt();
System.out.println("Square of "+ num + " is: "+ Math.pow(num, 2));
}
}