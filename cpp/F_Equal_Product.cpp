#include<bits/stdc++.h>
using namespace std;
// 1≤x1<x2≤n

// 1≤y2<y1≤m

// x1⋅y1=x2⋅y2

// l≤x1⋅y1≤r

int main()
{
    int n,m,l,r;
    cin >> n >> m;
    cin >> l >> r;
    int flag = 0;
    int x1,x2,y1,y2;
    x1 = 1;
    while(x1 <= n)
    {
        y2 = l;
        flag = 0;
        while(y2<m)
        {   x2 = x1+ 1;
            y1 = y2+ 1;
            if(x1*y1 >= l && x1*y1 <= r && x1*y1 == x2*y2)
            {
                cout << x1 << y1 << x2 << y2 << endl;
                flag = 1;
                break;
            }
            y2++;
        }     
        if(!flag)
        {
            cout << -1 << endl;
        } 
        x1++;  
    }
}