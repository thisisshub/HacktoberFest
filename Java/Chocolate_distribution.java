import java.util.*;
import java.io.*;

public class Main {

  public static int find(int[]arr, int n, int m) {
      Arrays.sort(arr);
    int i = 0 ;
    int j = m-1 ;
    int gap = Integer.MAX_VALUE ;
    while( j < n)
    {
        int temp = arr[j] - arr[i] ;
        // System.out.println(arr[j] + " " + arr[i]);
        gap = Math.min(gap , temp) ;
        j++;
        i++;
    }
    return gap;
  }

  public static void main(String[]args) {
    Scanner scn = new Scanner(System.in);
    //input work
    int n = scn.nextInt();
    int[]arr = new int[n];

    for (int i = 0; i < n; i++) {
      arr[i] = scn.nextInt();
    }

    int m = scn.nextInt();
    int ans = find(arr, n, m);

    System.out.println(ans);
  }
}
