import java.util.Scanner;

public class MinimumSwapToMakeTwoBinaryStringEqual {
    public static void main(String[] args) {
        Scanner obj=new Scanner(System.in);
        String s1=obj.next();
        String s2=obj.next();

        int ans = minSwaps(s1, s2);
        System.out.println(ans);

    }
    public static int minSwaps(String s1, String s2){
        int c0=0,c1=0;
        if(s1.length()!=s2.length()){
            return -1;
        }
        for (int i = 0; i <s1.length() ; i++) {

            //count of zeros
            if(s1.charAt(i)=='0' && s2.charAt(i)=='1'){
                c0++;
            }
//           Count of one's
            else if (s1.charAt(i)=='1' && s2.charAt(i)=='0'){
                c1++;
            }
        }
        int ans = (c0/2) + (c1/2);

        if(c0%2 ==0 && c1%2==0){
            return ans;
        }else if ((c0 + c1)%2==0){
            return ans+2;
        }else {
            return -1;
        }
    }
}
