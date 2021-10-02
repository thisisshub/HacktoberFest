#include<stdio.h>
int main(){
int a,n;
printf("Enter a and n to get a^n:");
scanf("%d %d",&a,&n);
printf("%d",powt(a,n));
}
int powt(int a,int n){
if(a==0)
    return 0;
if(n==0)
    return 1;
else
{
    return a*powt(a,n-1);
}
}
