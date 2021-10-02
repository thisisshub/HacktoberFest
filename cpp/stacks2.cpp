#include<bits/stdc++.h>
#include<vector>
#include<stack>

using namespace std;
int main(){
int a[]={1,3,2,4},i,n=4;
vector<int> v;
stack<int> s;
for(i=0;i<n;i++){
    if(s.size()==0)
        v.push_back(-1);
    else if( s.size()>0 && s.top() >a[i])
          {v.push_back(s.top());}
    else if( s.size()>0 && s.top()<=a[i]){
            while(s.size()>0 && s.top()<=a[i]){
                    s.pop();
                    }
            if(s.size()==0)
                v.push_back(-1);
            else
                v.push_back(s.top());
}
            s.push(a[i]);
}
for(i=0;i<n;i++){
    cout<<v[i]<<endl;
}

}
