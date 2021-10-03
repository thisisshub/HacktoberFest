#include <iostream>
using namespace std;
 
void findEl(int A[], int n)
{
    if (n == 0) {
        return;
    }
 
    int i, rs = 0;
    for (i = 0; i < n; i++) {
        rs += A[i];
    }
    int ls = A[0];
    for (int i = 1; i < n - 1; i++)
    {
        if (ls == rs - (A[i] + ls)) {
            cout<<"The element is "<<A[i];
        }
         ls += A[i];
    }
}
 
int main()
{
    int n, i;
    cin>>n;
    int *A = new int[n];
    for(i=0; i<n; i++){
        cin>>A[i];
    }
    findEl(A, n);
}
