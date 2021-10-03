/*
Smallest window in a string containing all the characters of another string 

Medium Accuracy: 42.59% Submissions: 35681 Points: 4
Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index. 

Example 1:

Input:
S = "timetopractice"
P = "toc"
Output: 
toprac
Explanation: "toprac" is the smallest
substring in which "toc" can be found.
Example 2:

Input:
S = "zoomlazapzo"
P = "oza"
Output: 
apzo
Explanation: "apzo" is the smallest 
substring in which "oza" can be found.
Your Task:
You don't need to read input or print anything. Your task is to complete the function smallestWindow() which takes two string S and P as input paramters and returns the smallest window in string S having all the characters of the string P. In case there are multiple such windows of same length, return the one with the least starting index. 

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(1)

Constraints: 
1 = |S|, |P| = 105
*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin >> t;
	while(t--){
	    string s1,s2;
	    cin >> s1 >> s2;
	    int l= s2.length();
	    int m= s1.length();
	    int gmax =m;
	    string str;
	    int a[255] ={0},frq[255]={0};
	    if(l>m || (l==m && s1!=s2))
	        cout << -1 << endl;
	    else{
    	    
    	    for(int i=0;i<l;i++)
    	        frq[s2[i]]++;
    	   // for(int i=0;i<l;i++)
    	   //     cout << frq[s2[i]] << " ";
    	    for(int i=0;i<m;i++){
    	        if(s2.find(s1[i])!=string::npos){
    	            a[s1[i]]++;
    	            string temp="";
    	            temp+=s1[i];
    	            int j=i+1;
    	            int x=l-1;
    	            while(j<m && x){
    	                if((s2.find(s1[j])!=string::npos)){
    	                    if(a[s1[j]]<frq[s1[j]]){
        	                    x--;
    	                        a[s1[j]]++;
    	                    }
    	                }
    	                    
    	                temp+=s1[j];
    	                j++;
    	            }
    	            
    	            if(x==0){
        	            if(gmax>temp.length()){
        	                gmax = temp.length();
        	                str = temp;
        	            }
    	            }
    	            fill(a,a+255,0);
    	        }
	        }
	        if(gmax==m)
	            cout << -1 << endl;
	        else
    	        cout << str << endl;
	    }
	}
	return 0;
}
