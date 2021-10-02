#include<stdio.h>
int main(){
int a[100],i,start,end,middle,key,n;
printf("Enter value of n::");
scanf("%d",&n);
printf("Enter values in an array in sorted way::");
for(i=0;i<n;i++)
    scanf("%d",&a[i]);
printf("Enter key to search::");
scanf("%d",&key);
start=0,end=n-1;
while(start<=end){
    middle=(start+end)/2;
    if(a[middle]==key)
        {
        printf("Element found");
        break;
        }

    if(a[middle]<key)
       start=middle+1;
    else
        end=middle-1;
}

if(start>end)
    printf("Element Not found");
}
