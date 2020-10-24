
//WRITE A JAVA PROGRAM TO COUNT THE NUMBER OF WORDS IN A SENTENCE STARTING WITH AN UPPER CASE LETTER
//12-06-2020

import java.util.*;

public class Capital_Letters {

	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
        System.out.println("Enter a Sentence");
        String s = " "+sc.nextLine();//Stores the entire sentence with a space in the beginning
        int f = 0;//Keeps track of the frequency of words starting with an uppercase letter

        //Loop for counting the numbewr of words starting with an uppercase letter
        for(int i=0;i<s.length()-1;i++){
            //If there is a space after which there is an uppercase character, f increases by 1
            if(s.charAt(i)==' ' && Character.isUpperCase(s.charAt(i+1))){
                f++;
            }
        }
        //Finally display the value of f, a.k.a frequency of words starting with an uppercase letter
        System.out.println("Words starting with uppercase : "+f);
	}
}
