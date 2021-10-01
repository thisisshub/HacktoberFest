import java.util.Scanner;  
public class KeithNumberExample1
{  
public static void main(String args[])   
{  
Scanner sc= new Scanner(System.in);  
System.out.print("Enter the number of digits the series must have: ");   
//reads an integer as length of the number from the user  
int numlen = sc.nextInt();  
//checks if the length of the number is greater than 2 or not  
if (numlen < 2)   
{  
//prints if the above condition returns false      
System.out.println("The number must have at least 2 digits.");  
}   
//executes if the above condition returns true  
else   
{  
//calculates the lower bound from where the series starts  
long lowBound = (long) Math.pow(10, numlen - 1);  
//calculates the upper bound from where the series ends  
long upperBound = (long) Math.pow(10, numlen);  
for (long l = lowBound; l < upperBound; l++)   
{  
if (isKeith(String.valueOf(l)))   
{  
//prints all the Keith number between given range      
System.out.print(l + ", ");  
}  
}  
}  
sc.close();  
}  
//function that checks whether the given number is Keith or not  
public static boolean isKeith(String input)   
{  
int numlen = input.length();  
//keep track only the last three terms  
long[] series = new long[numlen];  
for (int i = 0; i < numlen; i++)   
{  
series[i] = Long.valueOf(input.substring(i, i + 1));  
}  
long next_term = 0;  
long number = Long.valueOf(input);  
while (next_term < number)   
{  
next_term = 0;    
//calculates next term of the series  
for (int i = 0; i < numlen; i++)   
{  
next_term = next_term + series[i];  
if (i < numlen - 1)   
{  
//shift series to the left      
series[i] = series[i + 1];   
}   
else   
{  
//add new value to the series      
series[i] = next_term;   
}  
}  
//compares the next term of the series with the number and returns boolean value accordingly  
if (next_term == number)   
{  
return true;  
}  
}  
return false;  
}  
}  