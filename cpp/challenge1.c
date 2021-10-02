#include<stdio.h>
int main(){

    int a[100],i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int b[100],temp;
    for(i=0;i<n;i++){
        if(a[i]<38){
            b[i]=a[i];
        }else{
            if(a[i]%5==0){
                b[i]=a[i];
            }
            else{
                if(a[i]%10>=1 && a[i]%10<=4)
                {
                    temp=(a[i]/10)*10 +5;
                    b[i]=temp;
                }
                if(a[i]%10>=6 && a[i]%10<=9)
                {
                    temp=(a[i]/10)*10 +10;
                     b[i]=temp;
                }
            }
        }
    }
    for(i=0;i<n;i++){
        if(b[i]-a[i] <3)
            printf("%d ",b[i]);
        else{
             printf("%d ",a[i]);
        }
    }

}
