import java.util.Scanner;

public class Occurrence {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the number in which the occurrence of any digit would be checked");
        int n = input.nextInt();
        int number=n;
        System.out.println("Enter the digit to be count");
        int t = input.nextInt();
        int time = 0;
        int length = (int) (Math.log10(n) + 1);
        //System.out.println(length);
        for (int i = 0; i < length; i++) {
            int temp = n % 10;
            n = n / 10;
            if (temp == t) {
                time += 1;
            }
        }
        System.out.println("Occurrence of "+t+" is "+time+" in "+number);
    }
}
