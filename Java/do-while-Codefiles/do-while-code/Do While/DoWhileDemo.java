public class DoWhileDemo {
	public static void main(String[] args) {
		int n = 0;
		int x = 0;
		do {
			x = x + 1;
		} while (x * x < n);
		System.out.println(x * x == n);
	}
}