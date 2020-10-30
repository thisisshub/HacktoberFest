/*
Sort an array of 0s, 1s and 2s 
Given an array of size N containing 0s, 1s, and 2s; sort the array in ascending order.

Input:
First line of input contains number of testcases T. For each testcase, there will be two lines, first of which will contain N. The second lines contains the elements of the array.

Output: 
Print sorted array.

Your Task:
Complete the function sort012() that takes array and n and sorts the array in place. 

Constraints: 
1 <= T <= 50
1 <= N <= 10^5
0 <= A[i] <= 2

Example:
Input :
2
5
0 2 1 2 0
3
0 1 0

Output:
0 0 1 2 2
0 0 1

Explanation:
Testcase 1: After segragating the 0s, 1s and 2s, we have 0 0 1 2 2 which shown in the output.
*/

#include<bits/stdc++.h>
using namespace std;
void sort012(int[],int);

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

// } Driver Code Ends

void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void sort012(int a[], int n)
{
    // coode here 
    int l=0,mid=0,h=n-1;
    while(mid<=h){
        switch(a[mid]){
            case 0:
             swap(&a[l++],&a[mid++]);
             break;
            case 1:
             mid++;
             break;
            case 2:
             swap(&a[mid],&a[h--]);
             break;
        }
    }
}
