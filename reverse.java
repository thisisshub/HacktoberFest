import java.util.*;
public class reverse{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter a string : ");
    String inp = sc.nextLine();
    StringBuffer out = new StringBuffer(inp);
    System.out.println(out.reverse());
  }
}
