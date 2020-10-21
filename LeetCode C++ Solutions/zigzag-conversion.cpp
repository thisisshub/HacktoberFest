/**
 * Author: Siddhant Pandya
 * Problem: 6. ZigZag Conversion
 */


class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || numRows>=s.length())
        {
            return s;
        }
        
        vector<string> rows(numRows);
        string ans;
        int dir=1,pos=0;
        for(int x=0;x<s.length();x++)
        {
            rows[pos]=rows[pos]+s[x];
            if(dir==1)
            {
                if(pos<numRows-1)
                {
                    pos++;
                }
                else
                {
                    dir=0;
                    pos--;
                }
            }
            else
            {
                if(pos>0)
                {
                    pos--;
                }
                else
                {
                    dir=1;
                    pos++;
                }
            }
        }
        for(int i=0;i<numRows;i++)
        {
            ans=ans+rows[i];
        }
        return ans;
    }
};