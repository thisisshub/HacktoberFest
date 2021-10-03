import java.io.*;
import java.util.*;

public class fibonnaci {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        System.out.print("the ith fibonnaci number: ");

        int num = Integer.parseInt(sc.next());

        sc.close();

        long[] fibArray = new long[num];
        
        fibArray[0] = 0;
        fibArray[1] = 1;

        for(int i = 2; i < num; i++) {
            fibArray[i] = fibArray[i-1] + fibArray[i-2];
        }

        String output = "";

        for(int i = 0; i < num; i++) {
            output += fibArray[i];
            output += "\n";
        }
        System.out.println(output);
    }
}
