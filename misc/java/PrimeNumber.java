/*
 * 
 */
import java.util.*;

public class PrimeNumber {
	
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number to be checked if its Prime : ");
        int num = sc.nextInt();
        
        if(isPrime(num)){
            System.out.println(num+" is a Prime Number");
        }else{
            System.out.println(num+" is not a Prime Number");
        }
	}
    
    public static boolean isPrime(int x){
        if(x<=1){
            return false;
        }
        for(int i=2;i<=x/2;i++){
            if(x%i==0){
                return false;
            }
        }
        return true;
    }
}

