import java.io.*;
public class InputBufferedReader
{
 public static void main(String[] args) throws IOException 
 {
  String str,str1;
  int n;
  InputStreamReader isr = new InputStreamReader(System.in);
  BufferedReader br = new BufferedReader(isr);
  System.out.println("Enter your name");
  str=br.readLine();
  System.out.println("Enter your age");
  str1=br.readLine();
  n=Integer.parseInt(str1);
  System.out.println("The name is " + str);
  System.out.println("The age is " + n);
  }
}

