import java.util.Scanner;

public class Exponents {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int result = 1;

        System.out.println("Please enter the base");
        int base = input.nextInt(); //get the base from the user

        System.out.println("Please enter the power");
        int power = input.nextInt(); //get the power from the user

        for(int i = 0; i < power; i++){
            result *= base; //multiply the base itself
        }

        System.out.println(result);
    }
}
