//srishti1302
//counting inversions
import java.util.*;

class count_inverse
{
        static int getInvCount(int n,int arr[])
        {
                int inv_count = 0;
                for (int i = 0; i < n - 1; i++)
                        for (int j = i + 1; j < n; j++)
                                if (arr[i] > arr[j])
                                        inv_count++;
                return inv_count++;
        }


        public static void main(String[] args)
        {
                int k,x;
                System.out.println("ENTER THE VALUE OF N");
                Scanner ss=new Scanner(System.in);
                k=ss.nextInt();
                int arr[]=new int[k];
               
                for (int i=0;i<arr.length;i++)
                {
                        arr[i]=(int) (Math.random()*100);
                        System.out.println(arr[i]);
                }
                long start =System.nanoTime();
                x=getInvCount(k,arr);
                long end=System.nanoTime();
                System.out.print("Execution Time ");
                System.out.println(end-start);
                System.out.println("NUMBER OF INVERSIONS:"+x);
                ss.close();

        }

}
