import java.util.Scanner;

public class Reverse {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n= in.nextInt();
        int len = (int)(Math.log10(n)+1);
        for (int i=0;i<len;i++){
            int temp = n%10;
            n/=10;
            System.out.print(temp);
        }
    }
}
