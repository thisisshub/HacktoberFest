#include<stdio.h>
int main(){
int a[100],i=0,key,n;
printf("Enter value of n::");
scanf("%d",&n);
printf("Enter values in an array in sorted way::");
for(i=0;i<n;i++)
    scanf("%d",&a[i]);
printf("Enter key to search::");
scanf("%d",&key);
i=0;
while(i<n){
    if(a[i]==key)
       {
        printf("Element found");
        break;
}
i++;
}
if(i==n){
    printf("Element not flound");
}
}
