import java.util.Scanner;

public class OddEven {
    public static void main(String args[]) {
        int num;
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a number: ");
        num = scanner.nextInt();
        scanner.close();
        if (num % 2 == 0) {
            System.out.println(num + " is even");
        } else {
            System.out.println(num + " is odd");

        }

    }

}
