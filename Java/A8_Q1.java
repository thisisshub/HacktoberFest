import java.util.Scanner;
public class A8_Q1 {

	public static void main(String[] args) {
		
		Scanner n = new Scanner(System.in);
		
		System.out.print("Enter Value of M(Rows) : ");
		int m = n.nextInt();
		System.out.print("Enter Value of N(Columns) : ");
		int N = n.nextInt();
		
		int a[][] = new int[m][N];
		
		for(int i = 0;i<m;i++) {
			for(int j = 0;j<N;j++) {
					a[i][j] = n.nextInt();
			}
		}
			
		for(int i = 0;i<m;i++) {
			for(int j = 0;j<N;j++)
				 System.out.print(a[i][j]+" ");
		
			System.out.println();
		}
		
		

	}

}