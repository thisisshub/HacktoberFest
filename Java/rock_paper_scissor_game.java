// this is a rock paper scissor command line game

import java.util.Scanner;
import java.util.Random;

class rpsgame{
    public static void main(String args[] ) {
        System.out.println("\n            this is rock scissor paper game \n                   enter 113 to quit the game after every chance \n                    every player will get a chance \n                    so lets begin\n")  ;
        Random jj = new Random();
        Scanner ss = new Scanner(System.in);
 //     System.out.println(jj.nextInt(3));
        int compscore=0   , compchoice , userscore=0;
        int i = jj.nextInt(2);
        while(i!=113) {
            System.out.println("user enter your input press|| 0 for rock || 1 for paper || 2 for scissor \n");
            i = ss.nextInt();
            if(i==113) {
                break;
            }
            if(i<0||i>2) {
                System.out.println("enter correct input  \n");
                i = ss.nextInt();
            }
                compchoice = jj.nextInt(2);
                System.out.println("compchoice " + compchoice  + "\n");
                if(compchoice==i) {
                    System.out.println("\ndraw\n");
                }
                else if((compchoice==0)&&(i==1)) {
                    i++;
                    System.out.println("\nuser wins this turn\n");
                }
                else if((compchoice==0)&&(i==2)) {
                    compscore++;
                    System.out.println("\ncomp wins this turn\n");
                }
                else if((compchoice==1)&&(i==0)) {
                    compscore++;
                    System.out.println("\ncomp wins this turn\n");
                }
                else if((compchoice==1)&&(i==2)) {
                    i++;
                    System.out.println("\nuser wins this turn\n");
                }
                else if((compchoice==2)&&(i==0)) {
                    i++;
                    System.out.println("\nuser wins this turn\n");
                }
                else if((compchoice==2)&&(i==1)) {
                    compscore++;
                    System.out.println("\ncomp wins this turn\n");
                }
                userscore = i;
        }
        System.out.print("\nfinal scores are\nuser :  " + userscore + "\ncomp  :  " + compscore + "\n  winner is   :   " );
        if(userscore>compscore) {
            System.out.println("user\n");
        }
        else if(userscore<compscore) {
            System.out.println("comp\n");
        }
        else {
            System.out.println("match draw\n");
        }
        ss.close();
    }
}