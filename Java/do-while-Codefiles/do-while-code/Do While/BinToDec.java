public class BinToDec {
	public static void main(String[] args) {
		int nBin = 11010;
		int nDec = 0;
		int Pow2 = 1;
		while (nBin > 0) {
			nDec = nDec + (Pow2 * (nBin % 10));
			Pow2 = Pow2 * 2;
			nBin = nBin / 10;
		}
		System.out.println(nDec);
	}
}
