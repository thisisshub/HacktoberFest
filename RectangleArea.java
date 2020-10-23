import java.util.Scanner;

public class RectangleArea {
  public static void main(String args[]) {
    double length;
    double width;
    double area;
    Scanner scanner = new Scanner(System.in);
    System.out.println("Enter Length(cm): ");
    length = scanner.nextDouble();
    System.out.println("Enter Width(cm): ");
    width = scanner.nextDouble();
    scanner.close();
    area = length * width;
    System.out.println("Area of the rectangle(cm): " + area);
  }
}
