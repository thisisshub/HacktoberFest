import java.util.*;
class Q15{
    public static void main(String args[]){
        Scanner sc= new Scanner(System.in);
        System.out.println("enter length of array");
        int length= sc.nextInt();
        String s[] = new String[length],str,reverse[]=new String[length];
        System.out.println("enter string elements of array");
        int i ,j;
        sc.nextLine();
        for (i = 0;i<length ;i++){
        System.out.print(i+" ");
            s[i] = sc.nextLine();
        }
        for (i=length-1 ; i>=0 ; i--){
            str= s[i];
            String d="";
            for(j=str.length()-1;j>=0;j--){
                char ch= str.charAt(j);
                d+=ch ;
            }
            reverse[length - (i+1)] = d;
        }
        System.out.print("array is :");
        for (i =0;i<length ;i++){
        System.out.print(s[i]+" ");
        }
        System.out.println("\n");
        System.out.print("reverse array is :");
        for (i =0;i<length ;i++){
        System.out.print(reverse[i]+" ");
        }
        System.out.println("\n");
    }
}