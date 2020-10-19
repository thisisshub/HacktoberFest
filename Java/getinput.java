import java.util.Scanner;

class GetInputData
{
  public static void main(String args[])
  {
     int num;
     float fnum;
     String str;
 
     Scanner in = new Scanner(System.in);
 
     //Get input String
     System.out.println("Enter a string: ");
     str = in.nextLine();
     System.out.println("Input String is: "+str);
 
     //Get input Integer
     System.out.println("Enter an integer: ");
     num = in.nextInt();
     System.out.println("Input Integer is: "+num);
 
     //Get input float number
     System.out.println("Enter a float number: ");
     fnum = in.nextFloat();
     System.out.println("Input Float number is: "+fnum); 
  }
}


import java.util.Scanner;


class Marksheet
 {
    public static void main(String []args)
    {
        Scanner x=new Scanner(System.in);
        
        System.out.println("******Welcome to the Marksheet******");
        
        System.out.println("------------------------------------------");
        System.out.println("Enter the Name of Student \t:\t");
        String name=x.next();
        System.out.println("Enter the Roll Number \t:\t");
        int rollno=x.nextInt();
        System.out.println("Enter the College Name \t:\t");
        String clg=x.next();
        
        
        System.out.println("--------------------------------------------");
        
        System.out.println("Enter the Marks of Sub1 \t:\t");
        int s1=x.nextInt();
        System.out.println("Enter the Marks of Sub2 \t:\t");
        int s2=x.nextInt();
        System.out.println("Enter the Marks of Sub3  \t:\t");
        int s3=x.nextInt();
        System.out.println("Enter the Marks of Sub4 \t:\t");
        int s4=x.nextInt();
        System.out.println("Enter the Marks of Sub5 \t:\t");
        int s5=x.nextInt();
        
        System.out.println("Total Marks is \t:\t");
        int total=s1+s2+s3+s4+s5;
        System.out.println("Total="+total);
        
        System.out.println("Percentage \t:\t");
        float Per = total/5;
        System.out.println("Percentage="+Per);
       
        System.out.println("\n\n\t\t Marksheet");
        System.out.println("\n------------------------------------------------------------------------------");
        System.out.println("\n\tName\t\t:\t"+name);         
        System.out.println("\n\tRollno\t\t:\t"+rollno);
        System.out.println("\n\tCollege\t\t:\t"+clg);
        System.out.println("\n------------------------------------------------------------------------------");
        System.out.println("\n\tSubject\t\t:\tMarks");
        System.out.println("\n\tSub1\t\t:\t"+s1);
        System.out.println("\n\tSub2\t\t:\t"+s2);
        System.out.println("\n\tSub3\t\t:\t"+s3);
        System.out.println("\n\tSub4\t\t:\t"+s4);
        System.out.println("\n\tSub5\t\t:\t"+s5);
        System.out.println("\n-------------------------------------------------------------------------------");
        System.out.println("\n\tTotal\t\t:\t"+total);
        System.out.println("\n\tPercentage\t\t:\t"+Per);

    }                              
        
}
