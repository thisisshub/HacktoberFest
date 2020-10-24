import java.util.Scanner;

public class ExtractDigits {
  public static void main(String args[]) {
    int num, i;
    Scanner scanner = new Scanner(System.in);
    System.out.println("Enter a number: ");
    num = scanner.nextInt();
    scanner.close();
    System.out.println("Digits extracted: ");
    for (i = 0; i < 3; i++) {
      System.out.println(num % 10);
      num /= 10;
    }
  }
}
