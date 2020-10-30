import java.util.Scanner;
public class A8_Q7 {

	public static void main(String[] args) {
		
		Scanner n = new Scanner(System.in);
		
		System.out.print("Enter N for n*n Matrix : ");
		int N = n.nextInt();
		
		int a[][] = new int[N][N];
		
		System.out.println("Enter Matrix : ");
		
		for(int i = 0 ; i<a.length;i++)
			for(int j = 0;j<a[0].length;j++)
				a[i][j] = n.nextInt();
		
		System.out.println("After Transposing......");
		
		
		for(int i = 0 ; i<a.length;i++) {
			for(int j = 0;j<a[0].length;j++)
					System.out.print(a[j][i]+" ");
		
		System.out.println();
		}
		
	}	

}
