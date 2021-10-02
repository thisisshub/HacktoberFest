#include<stdio.h>
int main(){
    int h[]={7,10},f[]={4 ,12},mn[]={3 ,3},a[]={2 ,3 ,-4},b[]={3 ,-2,-4},i,m,n;

    m=mn[0];
    n=mn[1];

    for(i=0;i<m;i++){
        a[i]=a[i]+f[0];
    }
    for(i=0;i<n;i++){
        b[i]=b[i]+f[1];
    }
    int aa=0,bb=0;
    for(i=0;i<m;i++){
        if(a[i]>= h[0] && a[i] <=h[1])
            {aa++;}
    }
    for(i=0;i<n;i++){
        if(b[i]>=h[0] && b[i] <=h[1])
            {bb++;}
    }

    printf("%d\n",aa);
    printf("%d",bb);

}
