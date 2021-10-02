#include<stdio.h>
int main()
{
int a[]={3,2,4},i,j,t=6;
int n=3;
for(i=0;i<n;i++){
    for(j=i+1;j<n;i++){
        if(a[i]+a[j]==t)
            break;
    }
}
printf("%d %d",i,j);
}
