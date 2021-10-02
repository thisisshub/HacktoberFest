import java.util.*;
import java.io.*;

class shape {
    public static void main(String args[]) throws IOException {
        Scanner in =new Scanner (System .in);
        System.out.println("Enter length, height, and width");
        int x = in.nextInt();
        int y = in.nextInt();
        int z = in.nextInt();
        in.close();

        System.out.print("The area is: ");
        System.out.println(x*y*z);
    }
}
