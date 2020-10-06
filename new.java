class Exp3
{
	void Exp3(double x, double y,double z)
	{
		double m = (x+y+z)/3;
		System.out.println("Double avg = "+m);
	}
	void Exp3(int a,int b, int c)
	{
		int n = (a+b+c)/3;
		System.out.println("Integer Avg = "+n);
	}
	public static void main(String arg[])
	{
		Exp3 e = new Exp3();
		e.Exp3(1.2,3.4,5.6);
		e.Exp3(1,2,3);
	}
}
