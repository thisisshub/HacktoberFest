import java.util.*;
public class RangeSumQuery {
	
	public static int solve(int sum[],int i,int j) {
		if(i==0) {
			return sum[j];
		}
		
		return (sum[j]-sum[i-1]);
	}
	
	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		
		int n=sc.nextInt();
		int array[]=new int[n];
		
		for(int i=0;i<n;i++) {
			array[i]=sc.nextInt();
		}
		
		int sum[]=new int[n];
		sum[0]=array[0];
		
		for(int i=1;i<n;i++) {
			sum[i]=sum[i-1]+array[i];
		}
		
		int ans=solve(sum,0,n-1);
		
	}
}
