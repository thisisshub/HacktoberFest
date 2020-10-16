import java.util.Scanner;

public class LargestContinousSumSubarray {
    public static void main(String[] args) {
        Scanner obj=new Scanner(System.in);
        int n=obj.nextInt();
        int arr[]=new int[n];
        for (int i = 0; i <n ; i++) {
            arr[i]=obj.nextInt();
        }
        System.out.println(maxSubArraySum(arr));
    }

    static int maxSubArraySum(int arr[]){
        int size = arr.length;
        int max=Integer.MIN_VALUE, maxHere=0;
        for (int i = 0; i <arr.length ; i++) {
            maxHere = maxHere + arr[i];
            if(max<maxHere){
                max=maxHere;
            }
            if(maxHere<0){
                maxHere=0;
            }
        }
        return max;
    }
}
