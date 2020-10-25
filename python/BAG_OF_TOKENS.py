/*

You have an initial power of P, an initial score of 0, and a bag of tokens where tokens[i] is the value of the ith token (0-indexed).

Your goal is to maximize your total score by potentially playing each token in one of two ways:

If your current power is at least tokens[i], you may play the ith token face up, losing tokens[i] power and gaining 1 score.
If your current score is at least 1, you may play the ith token face down, gaining tokens[i] power and losing 1 score.
Each token may be played at most once and in any order. You do not have to play all the tokens.

Return the largest possible score you can achieve after playing any number of tokens.

*/



class Solution {
    public int bagOfTokensScore(int[] tokens, int P) {
        Arrays.sort(tokens);
        int len=tokens.length;
        int count=0;
        int f=0;
        int l=len-1;
        
        while(f<=l){
            if(P>=tokens[f]){
                P=P-tokens[f];
                count++;
                f++;
            }
            else if(count<1){   //this is because ,if count is 0 then we can't do any thing....
                break;
            }
            else{
                P=P+(tokens[l]-tokens[f]);
                f++;
                l--;
            }     
        }
        
        
        return count;
    }
}
