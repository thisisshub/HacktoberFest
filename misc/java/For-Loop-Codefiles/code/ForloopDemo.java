public class ForloopDemo 
{
	public static void main(String[] args) 
	{
		int i;
		for(i=10;i<100;i=i+1)
		{
			if((i%3==0) || (i%5==0))
			{
			System.out.println(i);
			}
		}
	}
}

