#include<bits/stdc++.h>
using namespace std;
bool valid(string s)
{
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            st.push(s[i]);
        }
       else if(s[i]==')')
        {
            if(!st.empty() && st.top()=='(')
            {
             st.pop();
            }
                else
            {
             return false;
              break;
            }
        }
         else if(s[i]=='}')
        {
            if(!st.empty() && st.top()=='{')
            {
             st.pop();
            }
                else
            {
             return false;
              break;
            }
        }
         else if(s[i]==']')
        {
            if(!st.empty() && st.top()=='[')
            {
             st.pop();
            }
                else
            {
             return false;
              break;
            }
        }
    }
    if(!st.empty())
    return false;
    else
    return true;
}
int main()
{
    string s;
    cout<<"ENTER STRING:"<<endl;
  cin>>s;
  if(valid(s))
  {
    cout<<"valid"<<endl;
  }
  else{
      cout<<"invalid string"<<endl;
  }
}
