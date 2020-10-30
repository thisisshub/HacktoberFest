import java.util.Scanner;

public class Prime {
    static Scanner input = new Scanner(System.in);
    
    public static void main(String [] args){
        prime();
    }
    
        public static void prime(){
        System.out.println("Enter a number to check if it is a prime.");
        
        //  The num variable holds a number supplied by the user.
        int num = input.nextInt();
        
        //  The flag variable holds the state of the number and it's initially set to false.
        //  If flag is true, the number is not a prime.
        //  If flag is false, the number is a prime.
        boolean flag = false;
        
        //  0 and 1 are not prime numbers, if either of them is entered flag is set to true
        if(num == 0 || num == 1){
            flag = true;
        }
        
        //  The loop checks if the number is divisible in the given range (2....num/2)
        //  If it is flag is set to true. i.e It is not a prime number
        for(int i = 2; i <= num/2; i++){
            if(num % i == 0){
                flag = true;
                break;
            } 
        }
        
        if(flag == true){
            System.out.println(num + " is not a prime number");
        }
        else{
            System.out.println(num + " is a prime number");
        }
    }
}
