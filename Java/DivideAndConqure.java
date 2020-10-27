//IT19048888
//S.P.Athige

import java.util.Scanner;

public class Ex2 {

	static int count = 0;

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);

		int N;
		N = scanner.nextInt();
		int[] A = new int[N];
		String out = "";

		for (int i = 0; i < N; i++) {
			A[i] = scanner.nextInt();
		}

		validateIndex(0, A, out);
	}

	static void validateIndex(int index, int arr[], String out) {
		if (index == arr.length) {
			System.out.println(count);
			System.out.println(out);
			return;
		} else
			searchElement(index, arr, out);
	}

	static void searchElement(int n1, int arr[], String out) {
		String s = "";
			s += out;
				for (int j = n1+1; j < arr.length; j++) {
		
					if(arr[n1] > arr[j]){
						count++;
						s += "("+arr[n1]+","+ arr[j]+")";
				}			
			}
				validateIndex(n1 + 1,arr,s);
	}	
}