//A CPP program to find the smallest Lexiographic string

#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    string D,S;
    cin>>D>>S;
    string output="";
    sort(S.begin(), S.end());
    for(int i=0;i<D.length();i++)
    {
      for(int j=0;j<S.length();j++)
      {
        if(D[i]==S[j])
        {
          output+=S[j];
          if(D[i]!=S[j+1])
            break;
        }
      }
    }
    cout<<output<<"\n";
  }
  return 0;
