// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void printNos(int N);
/* Driver program to test printNos */
int main()
{
    int T;
    
    //taking testcases
    cin>>T;
    
    while(T--)
    {
        int N;
        
        //input N
        cin>>N;
        
        //calling printNos() function
        printNos(N);
        
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


//Complete this function
void printNos(int N)
{
    //Your code here
    if(N==0)
        return;
    printNos(N-1);
    cout<<N<<" ";
    
}