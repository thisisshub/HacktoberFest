/*
Product array puzzle 
Given an array A of size N, construct a Product Array P (of same size) such that P is equal to the product of all the elements of A except A[i].

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each testcase contains two lines of input. The first line is N. The second line contains N elements separated by spaces.

Output:
For each testcase, print the Product array P.

Constraints:
1 <= T <= 10
1 <= N <= 1000
1 <= Ai <= 20

Example:
Input:
2
5
10 3 5 6 2
2
12 20
Output:
180 600 360 300 900
20 12

Explanation:
Testcase1: For the product array P, at i=0 we have 3*5*6*2. At i=1 10*5*6*2. At i=2 we have 10*3*6*2. At i=3 we have 10*3*5*2. At i=4 we have 10*3*5*6
So P is 180 600 360 300 900
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
int t;
cin>>t;
while(t--)
{
int n;
long long p=1;
cin>>n;
int arr[n];
for(int i=0;i<n;i++) { cin>>arr[i];
p=p*arr[i];
}

for(int i=0;i<n;i++) { cout<<(p/arr[i])<<" "; }
 cout<<endl; }
 return 0;
 }
 
 
