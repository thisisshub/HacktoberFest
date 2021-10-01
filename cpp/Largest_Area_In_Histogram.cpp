#include<bits/stdc++.h>

using namespace std;

int HISTOGRAM(vector<int> &v, int n)
{
    vector<int> ans2;
    stack<int>st;

    for(int i=0;i<n;i++)
    {
        while(!st.empty() && v[st.top()] >= v[i])
            st.pop();
        ans2.PB( (st.empty()) ? -1 : st.top());
        st.push(i);
    }
    while(!st.empty())
        st.pop();
    vector<int> ans;
    reverse(v.begin(), v.end());
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && v[n-1-st.top()] >= v[i])
            st.pop();
        ans.PB( (st.empty()) ? n : st.top());
        st.push(n-i-1);
    }
    reverse(ans.begin(), ans.end());
    reverse(v.begin(), v.end());
    int ans3 = 0;
    for(int i=0;i<n;i++)
    {
        ans3 = max(ans3,v[i]*(ans[i]-ans2[i]-1));
    }
    return ans3;
}

int main()
{
    int n = 6;
    vector<int> v = {2,3,4,5,6,1};
    int v2 = HISTOGRAM(v,n);
    cout<<v2;
}
