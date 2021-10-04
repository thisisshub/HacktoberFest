#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n, count = 0;
  cin>>n;
  while(n!=0)
  {
    n = n/10;
    ++count;
  }
 cout<<count;  
return 0;
}