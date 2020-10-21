public class NestedIfDemo {
   public static void main(String args[]) {
	/*//int n = -5;
	//int n=5;
	int n=10;
	if (n < 0) {
	System.out.println("Negative number");
   }
	else{
	if (n % 2 == 0) {
   System.out.println("Even number");
	}
	else {
   System.out.println("Odd number");
	}
	}
   }*/
	int n, nHalf;
	n = 5;

	/*if (n % 2 == 0) {
	nHalf = n / 2;
	}
	else {
	nHalf = (n + 1) / 2;
	}*/
	nHalf = n % 2 == 0 ? n / 2 : (n + 1) / 2;
	System.out.println(nHalf);
}
