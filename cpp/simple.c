#include<stdio.h>
int main(){
int i,rev=0,rem;
for(i=10;i<=99;i++){
while(i!=0){
    rem=i%10;
    rev=rev*10 + rem;
    i=i/10;
}
    if(i*3 ==rev)
        printf("%d %d ",i,rev);
        break;

}
}
