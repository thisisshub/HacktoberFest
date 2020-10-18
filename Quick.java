import java.util.Scanner;
class Insertion
{
public static void sorting(int A[]) 
{   int n = A.length;
    int i,j,t;  
    for(i=1;i<n;i++)  
	{      
        j=i-1;   
		t=A[i];    
		while(j>-1 && A[j]>t)        
		{           
  	        A[j+1]=A[j];            
			j--;        
		}       
		A[j+1]=t;   
	}  
	  
 }
public static void main(String[]args)
{   
    Scanner sc = new Scanner(System.in);
	int x,y;
	System.out.println("enter the number of integer elements:");
	x = sc.nextInt();
	int A[]=new int[x];
	System.out.println("enter the elements:");
	for(y=0;y<x;y++)
		A[y] = sc.nextInt();
	sorting(A);
	System.out.println("elements after sorting:");
	for(y=0;y<x;y++)
		System.out.print(A[y]+",");
	 
}
}
