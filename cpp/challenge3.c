#include<stdio.h>
int main(){
int a[4],i,x1,x2,v1,v2,temp;
for(i=0;i<4;i++){
        scanf("%d",&a[i]);
    }
x1=a[0],x2=a[2],v1=a[1],v2=a[3];
if(((v1 > v2) && (x2 - x1) % (v2 - v1) == 0) || ((x1-x2) % (v2-v1) == 0 && v1>v2))
    {printf("YES");}

else
    {printf("NO");}
}
