class A extends Thread
{   public void run()
	{	for(int i = 1;i<=100;i++)
			System.out.println("Tread A: i = "+i);
		System.out.println("Exit from Tread A");
	}
}

class B extends Thread
{   public void run()
	{	 
		for(int j = 1;j<=100;j++)
			System.out.println("Tread B: j = "+j);
		System.out.println("Exit from Tread B");
	}
}

class C extends Thread
{	public void run()
	{	 
		for(int k = 1;k<=100;k++)
			System.out.println("Tread C: k = "+k);
		System.out.println("Exit from Tread C");
	}	
}

class threadjoin
{
	public static void main(String [] args)
	{   A t1 = new A();
		B t2 = new B();
		C t3 = new C();

		t1.start();
		try
		{
			t1.join();  
		}
		catch(Exception e)
		{
			System.out.println(e);
		}

		t2.start();
		t3.start();
	}
}
