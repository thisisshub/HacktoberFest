//QUESTION :

/* Chef Ada has a matrix with N rows (numbered 1 through N from top to bottom) and N columns (numbered 1 through N from left to right) containing all integers between 1 and N2 inclusive. For each valid i and j, let's denote the cell in the i-th row and j-th column by (i,j).

Ada wants to sort the matrix in row-major order ― for each valid i and j, she wants the cell (i,j) to contain the value (i−1)⋅N+j.

In one operation, Ada should choose an integer L and transpose the submatrix between rows 1 and L and columns 1 and L (inclusive). Formally, for each i and j (1≤i,j≤L), the value in the cell (i,j) after this operation is equal to the value in (j,i) before it.

The initial state of the matrix is chosen in such a way that it is possible to sort it using a finite number of operations (possibly zero). Find the smallest number of operations required to sort the matrix.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The next N lines describe the matrix. For each valid i, the i-th of these lines contains N space-separated integers ― the initial values in cells (i,1),(i,2),…,(i,N).
Output
For each test case, print a single line containing one integer ― the smallest number of operations required to sort the matrix.

Constraints
4≤N≤64
the sum of N2 over all test files does not exceed 3⋅105
Subtasks
Subtask #1 (10 points):

T≤50
N=4
Subtask #2 (90 points): original constraints

Example Input
1
4
1 2 9 13
5 6 10 14
3 7 11 15
4 8 12 16
Example Output
2
Explanation
Example case 1: After the first operation, with L=2, the resulting matrix is

1 5 9 13
2 6 10 14
3 7 11 15
4 8 12 16
After the second operation, with L=4, the matrix becomes sorted

1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
*/

// SOLUTION :

#include <bits/stdc++.h>
using namespace std;
class ABC{
    public:
    int check(vector<vector<int>> &arr,int n){
        int count=0;
        for(int j=n-1;j>0;j--){
	        if(arr[0][j]!= j+1)
	            {
	                int l=j;
	                transpose(arr,l);
	                count++;
	            }
        }
        return count;
        
    }
    static void transpose(vector<vector<int>> &arr,int l){
        for(int i=1;i<=l;i++){
            for(int j=0;j<i;j++){
                swap(arr[i][j],arr[j][i]);
            }
        }
        
    }
};

int main() {
	int t;
	ABC obj;
	cin>>t;
	
	while(t>0){
	    int n;
	    cin>>n;
	    vector<vector<int>> arr(n,vector<int>(n));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            cin>>arr[i][j];
	            
	        }
	    }
	    int c=obj.check(arr,n);
	    cout<<c<<endl;
	    t--;
	}
	return 0;
}
