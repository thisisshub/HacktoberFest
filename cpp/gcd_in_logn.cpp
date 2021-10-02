#include<iostream>
using namespace std;
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int main(){
    int a,b,ans;
    cin>>a>>b;
    ans=gcd(a,b);
    cout<<ans<<endl;
}