import java.util.Scanner;
public class A5_Q20 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner n = new Scanner(System.in);
		
		int a = n.nextInt();
		int i = 2;
		while(a>0) {
			
				if(a%i==0) {
					System.out.print(i+" ");
					a/=i;
				}		
				else {
					i++;
				}
			
		}
		
		
		
	}

}
