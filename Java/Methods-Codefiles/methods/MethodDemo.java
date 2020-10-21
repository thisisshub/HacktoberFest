public class MethodDemo
{
 public static int displayMessage()
 {
   System.out.println("Hello Method");
   //square(5);
   return 7;
 }
 public void square(int a)
 {
   System.out.println(a*a);
 }
 public static void main(String arg[])
 {
   //MethodDemo md = new MethodDemo();
   System.out.println(displayMessage());
   Demo d = new Demo();
   d.show();
 }
}


