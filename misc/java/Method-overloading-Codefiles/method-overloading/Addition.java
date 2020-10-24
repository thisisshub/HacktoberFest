
public class Addition {

	int a=10,b=5;
	void add()
	{
		System.out.println(a+b);
	}
	void add(double num1, double num2)
	{
		System.out.println(num1 + num2);
	}
	void add(int n1, int n2, int n3)
	{
		System.out.println(n1+n2+n3);
	}
	void add(String s1,String s2)
	{
		System.out.println(s1+s2);
	}
	public static void main(String[] args) {
		Addition obj = new Addition();
		obj.add();
		obj.add(2.5,3);
		obj.add(1,5,4);
		obj.add("Hello", " World");
		
	}

}

