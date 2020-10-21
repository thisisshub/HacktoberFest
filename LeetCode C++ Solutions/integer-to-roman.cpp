/**
 * Author: Siddhant Pandya
 * Problem: 12. Integer to Roman
 */

class Solution {
public:
    string intToRoman(int num) {
        string s;
        int values[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string strs[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        for(int x=0;x<13;x++)
        {
            while(num>=values[x])
            {
                num-=values[x];
                s+=strs[x];
            }
        }
        return s;
    }
};