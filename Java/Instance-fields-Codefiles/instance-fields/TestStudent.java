public class TestStudent 
{
	public static void main(String args[])
{
Student stud1 = new Student();
Student stud2=new Student();
Student stud3=new Student();
//Student stud2=stud1;
stud1.roll_no=20;
stud1.name="Ramu";
stud2.roll_no=30;
stud2.name="Shyamu";
System.out.println("The roll number is" + stud1.roll_no);
System.out.println("The name is " + stud1.name);
System.out.println("The roll number is" + stud2.roll_no);
System.out.println("The name is" + stud2.name);
System.out.println("The roll number is" + stud3.roll_no);
System.out.println("The name is " + stud3.name);
}
}
