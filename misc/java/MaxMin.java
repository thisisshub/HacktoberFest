import java.util.*;
class maxmin
{
    public static void main(String args[])
    {
        int arr[] = new int[10];
        int i,max,min;
        System.out.println("Enter ten elements in the array");
        Scanner sc = new Scanner(System.in);
        for(i = 0 ; i<10 ; i++)
        {
            arr[i] = sc.nextInt();
        }
        max = arr[0];
        min = arr[0];
        for(i = 0; i<10; i++)
        {
            if(arr[i] > max)
            {
                max = arr[i];
            }
            if(arr[i] < max)
            {
                min = arr[i];
            }
        }
        System.out.println("The largest number is " +max);
        System.out.println("The smallest number is " +min);
    }
}
