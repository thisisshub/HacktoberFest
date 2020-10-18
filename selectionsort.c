#include<stdio.h>

int main(){
    int n, i, j, c, m;
    
    printf("enter the value of n:");
    scanf("%d", &n);
    int A[n];

    for(i=0; i<n; i++){
      scanf("%d", &A[i]);
    }

    for(i=0; i<n; i++){
      c=A[i];
      m=i;
      for(j=i+1; j<n; j++){
        if(A[j]<c){
          c=A[j];
          m=j;
        }
      }
    A[m]=A[i];
    A[i]=c;
    }

    for(i=0; i<n; i++){
      printf("%d ", A[i]);
    }

    return 0;
}
