public class Prime {
    public static void main(String[] args) {
        int num = 10;
        boolean isPrime = true;
        
        if(num == 0 || num == 1 || num == -1){ //if num is -1, 0, or 1 then it is not a prime
            isPrime = false;
        }
        else
        {
            //this loop will divide the number by all the numbers below it except for 1 to see if any of them are divisible. If none of them are then the number is a prime
            for(int i = num - 1; i > 1; i--){
                System.out.println(i);
                if(num % i == 0){  //If the number is divisible then it will break out of the loop because it is not a prime
                    isPrime = false;
                    break;
                }
            }
        }
        System.out.println("Is Prime? " + isPrime);
    }
}
