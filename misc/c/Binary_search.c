#include<stdio.h>

int A[50];
int binary_search(int s, int f, int val);

int main(){
    int n, val, x, i;
    printf("enter the value of n: ");
    scanf("%d", &n);
    printf("enter the values in array: ");
    for(i=0; i<n; i++){
        scanf("%d", &A[i]);
      }
    printf("enter the value to be searched: ");
    scanf("%d", &val);
    x=binary_search(0, n-1, val);
    printf("%d", x);


    return 0;
}
int binary_search(int s, int f, int val){
    int m;
    if(s==f & A[s]!=val)
        return 0;
    if(s!=f){
    m=(f+s)/2;
    if(A[m]==val)
      return 1;
    if(val < A[m]){
        f=m-1;
        return binary_search(s, f, val);
    }
    if(val > A[m]){
        s=m+1;
        return binary_search(s, f, val);
      }
    }
}
