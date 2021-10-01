import java.util.Scanner;  
public class UniqueNumberEg
{  
public static void main(String args[]){  
int r1, r2, number, n1, n2, count = 0;  
Scanner sc=new Scanner(System.in);  
System.out.print("Enter the number: ");  
number = sc.nextInt();    
n1=number;  
n2=number;  
while(n1 > 0){  
r1 = n1 % 10;  
while(n2 > 0){  
r2 = n2 % 10;
if(r1 == r2)  
{  
count++;  
}  
n2=n2/10;  
}
n1=n1/10;  
}  
if(count==1)  
{  
System.out.println("Number is unique");  
}  
else  
{  
System.out.println("Number is not unique");  
}  
}  
}  
