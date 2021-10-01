/* Solving Que. 1832 Check if the Sentence Is Pangram => https://leetcode.com/problems/check-if-the-sentence-is-pangram/submissions/ */

import java.util.Arrays;

public class isPangramSentence {
    public static void main(String[] args) {
        String sentence = "aaaaaaaaa";
        boolean[] arr = new boolean[26];

        for (int i = 0; i < sentence.length() ; i++) {
            arr[sentence.charAt(i) - 97] = true;
        }
        boolean a =isPan(arr);
        System.out.println(a);
    }

    public static boolean isPan(boolean[] arr)
    {
        for (int i = 0; i < 26 ; i++) {
            if (arr[i] == false)
            {
                return false;
            }
        }
        return true;
    }
}
