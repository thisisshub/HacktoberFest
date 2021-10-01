#include<bits/stdc++.h>
using namespace std;
int main() {
int n ; 
cout<<"Enter the size of the Pattern : ";
cin>>n;
cout<<"Here is your output : "<<endl;
for(int i = 0 ; i<n;i++){
    for(int j= 0 ; j<n;j++){
        if(i==0 || j == 0 || i==n-1 || j==n-1){
            cout<<"* ";
        }
        else
        cout<<"  ";
    }
    cout<<endl;
}

return 0;

}