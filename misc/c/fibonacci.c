#include<stdio.h>

int main(){
    int a, b, x, n, i;
    printf("Enter the value of n:");
    scanf("%d", &n);
    a=0;
    b=1;
    if(n==0){
        printf("n should be >= 1");
    }
    if(n==1){
        printf("%d", a);
    }
    if(n==2){
        printf("%d%d", a, b);
    }
    if(n>2){
        printf("%d%d", a, b);
    }
    for(i=1; i<=n-2; i++){
        x=a+b;
        printf("%d", x);
        a=b;
        b=x;
    }
    return 0;
}
