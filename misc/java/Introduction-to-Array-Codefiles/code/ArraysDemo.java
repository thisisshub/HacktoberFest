class ArraysDemo
{
	public static void main(String arg[])
	{
	int squares[] = new int[10];
	  
	  int n, x;
	  for(x=0;x<10;x=x+1)
	  {
		  n=x+1;
		  squares[x]=n*n;
	  }
	  System.out.println(squares[2]);
	  }
}
