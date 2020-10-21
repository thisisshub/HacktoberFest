public class ReverseNumber {
	public static void main(String[] args) {
		int n = 19435;
		int rNum = 0;
		while (n > 0) {
			rNum = rNum * 10 + (n % 10);
			n = n / 10;
		}
		System.out.println(rNum);
	}
}
