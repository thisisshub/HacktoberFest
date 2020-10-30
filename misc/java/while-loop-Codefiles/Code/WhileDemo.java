public class WhileDemo {
	public static void main(String[] args) {
		int n = 13876;
		int dSum = 0;
		while (n > 0) {
			dSum = dSum + (n % 10);
			n = n / 10;
		}
		System.out.println(dSum);
	}
}