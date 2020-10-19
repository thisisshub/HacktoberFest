// to check how many no are > ,= and  < to a no. in an array 
//for example in an raay of [1,2,3,4,4,5] given no. is 4 then iteems equal to 4 are 2, > 4 are 1 ,and < 4 are 2.
import java.util.*;
class No_of_instances{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("enter length of array");
        int l  = sc.nextInt(), a[] = new int[l];
        int i , largerCount=0 , smallCount= 0 ,equalCount=0;
        System.out.println("enter numbers in array:-");
        for(i=0;i<l;i++)
        a[i] = sc.nextInt();

        System.out.println("your array is:- ");
        for(i=0;i<l;i++)
        System.out.print(a[i]+" ");
        
        System.out.println();
        System.out.println("enter no to check :-");
        int n = sc.nextInt();
        for(i=0;i<l;i++){
            if(n==a[i]) equalCount++;
            else if(n<a[i]) smallCount++;
            else largerCount++;
        }
        System.out.println();
        System.out.println("elements of array equal to"+n+" are : "+equalCount);
        System.out.println("elements of array larger than "+n+" are : "+largerCount);
        System.out.println("elements of array smaller than "+n+" are : "+smallCount);
    }
}
import java.util.Scanner;
class AdditionMatrices
{
	public static void main(String args[])
	{
	 
	 Scanner x=new Scanner(System.in);

	 System.out.println("Enter the number of rows");
     System.out.println("Enter the number of columns");

      int a,b;
	  a=x.nextInt();
	 b=x.nextInt();

     int first[][]=new int[a][b];
     int second[][]=new int[a][b];

     int sum[][]=new int[a][b];

     System.out.println("Enter elements of first matrix");
     for(int i=0;i<a;i++)
     {
     for(int j=0;j<b;j++)
     {
     	first[i][j]=x.nextInt();
}
     }
     System.out.println("Enter elements of second matrix");
     for(int i=0;i<a;i++)
     {
     	for(int j=0;j<b;j++)
     	{
     		second[i][j]=x.nextInt();
     	}
     }
     System.out.println("new matrix after sum");
     for(int i=0;i<a;i++)
     {
     	for(int j=0;j<b;j++)
     	{
     		sum[i][j]=first[i][j]+second[i][j];
     		System.out.println(sum[i][j]+ "\t");
     	}
     	System.out.println();
     }
     }


	
}
