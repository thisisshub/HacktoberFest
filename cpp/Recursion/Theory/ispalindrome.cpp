#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end)
{
    if(start>=end){
        return true;
    }

    return (isPalindrome(s,start+1,end-1) and (s[start]==s[end]));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "cafac";
    printf("%s", isPalindrome(s, 0, s.length() - 1) ? "True" : "False");

    return 0;
}