
public class Que1 
{
	public static int factorial(int x)                                   //for finding factorial of a number
	{
		if (x==0 || x==1)
		{
		return 1;
		}
		
		else
		{
			int i;
			int fact=1;
			for (i=1;i<=x;i++)
			{
				fact= fact*i;
			}
			return fact;
		}
	}
	
	public static int SpecialNum(int y)                          //for checking if a number is special or not 
	{
		int temp,sum=0,reminder,factorial_;
		for (temp=y;temp>0;temp=temp/10)
		{
			reminder=temp%10;
			factorial_=factorial(reminder);
			sum=sum+factorial_;
			
		}
		return sum;
		
	}
	
	public static void main(String args[]) //for finding special number between 1 to 10000
	{
		int j,Temp,Sum=0;
		for (j=1;j<=10000;j++)
		{
			Temp=j;
			Sum= SpecialNum(Temp);
			
			if(j==Sum)
			{
			System.out.println(j);
			}
			
		}
	}

}
