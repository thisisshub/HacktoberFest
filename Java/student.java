import java.util.*;
public class student
{
	public int rollno , m1 ,m2 ,m3;
	public String name , grade;
	student (String n ,int a)
	{
		rollno = a;
		name = n;
	}
	public void marks()
	{
		System.out.println("marks subject 1 :");
		m1 = my.nextInt();
		System.out.println("marks subject 2 :");
		m2 = my.nextInt();
		System.out.println("marks subject 3 :");
		m3 = my.nextInt();
	}
	public char grade()
	{
		char grade;
		int t1=m1+m2+m3; 
		 if(t1>=250) grade ='A'; 
		 else if(t1>=200) grade='B'; 
		 else if(t1>=150) grade='C'; 
		 else if(t1>=100) grade='D'; 
		 else grade='E'; 
		return grade;
	}
	public  void disp() 
	 { 
		System.out.println("____________________________________"); 
		System.out.print("register number : " + rollno); 
		System.out.println("   Name : " +name);
		System.out.println("Mark1" +m1+"  | Mark2" +m2+"  | Mark3" +m3); 
		System.out.println("your grade is : "+grade()); 
		System.out.println("____________________________________");
		} 
	public static Scanner my = new Scanner(System.in);
	
public static void main(String args[])
{
	System.out.println("number of students ? : ");
	int n = my.nextInt();

	while(n>10 || n<0)
	{
		System.out.println("number of students ? ( 0 - 10 ) : ");
		n = my.nextInt();
	}
	student[] students = new student[n];
	System.out.println("Enter student details(name and roll no) for "+n+" students");
	for(int i =0;i<n;i++)
	{
		System.out.println("Enter name and roll no for "+i+"th student");
		students[i] = new student(my.next(), my.nextInt());
	}
	
	System.out.println("Enter student Marks for 3 subjects for "+n+" students");
	for(int i =0;i<n;i++)
	{
		System.out.println("Enter student Marks for "+i+"th student");
		students[i].marks();
		
	}
	System.out.println("All stuent data : ");
	for(int i =0;i<n;i++)
	{
		System.out.println("details for student "+i+" is :");
		students[i].disp();
	}
	
	System.out.println("\nwhose details you want enter index no. ");
	try 
	{
		students[my.nextInt()].disp();
	}
	catch(ArrayIndexOutOfBoundsException e) 
	{
        System.out.println("The index you have entered is invalid");
        System.out.println("Please enter an index number between 0 and "+(n-1));
     }
}
}