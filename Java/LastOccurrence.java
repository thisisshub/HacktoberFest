//SasmithaAthige

import java.util.Scanner;

public class Ex1 {
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int N,index = -1;
		N = scanner.nextInt();
		int list[] = new int[N];
		int item = scanner.nextInt();
		int l =0;

		while(l < N) {			
			list[l] = scanner.nextInt();
			l++;
		}
		
		int k = 0;	
		while(k < N) {
			
			if( list[(N-1) - (k)] == item) {
				index =((N - k));
				break;
			} 

			k++;
		}
		
		System.out.println(index);
	}
}