/*
Remove all duplicates from a given string 
Given a string Str which may contains lowercase and uppercase chracters. The task is to remove all duplicate characters from the string and find the resultant string. The order of remaining characters in the output should be same as in the original string.

Example 1:

Input:
Str = geeksforgeeks
Output: geksfor
Explanation: After removing duplicate
characters such as e, k, g, s, we have
string as "geksfor".
*/


#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s1;
	    cin>>s1;
	    set<char> hash;
	    for(int i=0;i<s1.length();i++)
	     {if(hash.find(s1[i])==hash.end())
	      cout<<s1[i];
	     hash.insert(s1[i]);}
	     cout<<endl;
	}
	return 0;
}
