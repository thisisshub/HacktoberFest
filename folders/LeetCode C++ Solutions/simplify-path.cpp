/**
 * Author: Siddhant Pandya
 * Problem: 71. Simplify Path
 */

class Solution {
public:
    string simplifyPath(string path) {
        stack <string> st;
        stack <string> st2;
        string ans="";
        string tst="";
        
        istringstream ss(path);
        while(getline(ss,tst,'/'))
        {
            if(tst=="." || tst=="")
            {
                continue;
            }
            else if(tst=="..")
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(tst);
            }
        }
        
        while(!st.empty())
        {
            st2.push(st.top());
            st.pop();
        }
        
        while(!st2.empty())
        {
            ans=ans+"/";
            ans=ans+st2.top();
            st2.pop();
        }
        if(ans=="")
        {
            ans="/";
        }
        return ans;
    }
};