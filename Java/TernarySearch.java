public class TernarySearch {
	public static int ternarySearch(int low, int high, int key, int[] sortedArray) {
		if (high >= low) {
			int mid1 = low + (high - low) / 3;
			int mid2 = high - (high - low) / 3;
			if (sortedArray[mid1] == key) {
				return mid1;
			}
			if (sortedArray[mid2] == key) {
				return mid2;
			}
			if (key < sortedArray[mid1]) {
				return ternarySearch(low, mid1 - 1, key, sortedArray);
			}
			else if (key > sortedArray[mid2]) {
				return ternarySearch(mid2 + 1, high, key, sortedArray);
			}
			else {
				return ternarySearch(mid1 + 1, mid2 - 1, key, sortedArray);
			}
		}
		return -1;
	}
	public static void main(String[] args) {
		int low, high, p, key;
		int sortedArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        low = 0;
        high = 9;
		key = 5;
		p = ternarySearch(low, high, key, sortedArray);
		System.out.println("Index of " + key + " is " + p);
		key = 50;
		p = ternarySearch(low, high, key, sortedArray);
		System.out.println("Index of " + key + " is " + p);
	}
}