public class A  {
int a ;
{
System.out.println("Non static block of an instance of Class A");
System.out.println("The value of a is " + a);
}
{
System.out.println("Second non-static block of an instance of Class A");
System.out.println("The value of a is " +a);
}
public A()  
{
System.out.println("Constructing object of type A");
System.out.println("The value of a is" + a);
}
}
