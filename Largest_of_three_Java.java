import java.util.Scanner;

public class BiggestOfThree {
    public static void main(String args[]) {
        int a, b, c;
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter Number A: ");
        a = scanner.nextInt();
        System.out.println("Enter Number B: ");
        b = scanner.nextInt();
        System.out.println("Enter Number C: ");
        c = scanner.nextInt();
        scanner.close();
        if (a >= b && a >= c) {
            System.out.println(a + " is larger than " + b + " and " + c);
        } else if (b >= a && b >= c) {
            System.out.println(b + " is larger than " + a + " and " + c);
        } else {
            System.out.println(c + " is larger than " + a + " and " + b);

        }

    }

}
