#include <bits/stdc++.h>
using namespace std;

int binToDec(string s){
    int n = s.size();
    int i = 1;
    int ans = 0;
    for(int j=n-1; j>=0; j--){
        ans = ans + i*(s[j]-'0');
        i *= 2;
    }
    return ans;
}

int main()
{
    int n;
    string s;
    cout<<"Enter Binary number : ";
    cin>>s;
    cout<<"The decimal value of this number is : "<<binToDec(s)<<endl;
}
