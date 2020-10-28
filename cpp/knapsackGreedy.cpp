#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<utility>

using namespace std;



int main()
{
    pair<int,int> p;
    unordered_map<float,pair<int,int>> m;
    int v,w;
    int n;
    cin>>n;
    int cap;
    cout<<"cap: ";
    cin>>cap;
    float vw[n] = {0};
    float profit = 0;
    for(int i=0;i<n;i++){
        cin>>v>>w;
        p.first = v;
        p.second = w;
        vw[i] = (float) v/w;
        cout<<vw[i]<<" ";
        m[vw[i]] = p;
    }
    sort(vw,vw+n);
    for(int i=n-1;i>=0;i--){

        int x = vw[i];
        cout<<"vw = "<<vw[i];
        p = m[x];
        v = p.first;
        w = p.second;
        if(w <= cap){
            profit += v;
            cap -= w;
            cout<<"cap: "<<cap<<" ";
        }
        else{
            profit += (vw[i]*cap);
            cap -=w;
        }
        if(cap == 0){
            break;
        }
    }
    cout<<"\nprofit: "<<profit;
}
