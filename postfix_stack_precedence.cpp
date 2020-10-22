#include<iostream>
using namespace std;

char pop(int *stk,int &t)
{
  char d;
  if(t==-1)
    return -1;
  else
  {
    d=stk[t--];
    return d;
  }
}

void push(int *stk,char x,int &t)
{
  stk[++t]=x;
}

int prop(char x)
{
  if(x=='(')
   return 0;
  else if(x=='+' || x=='-')
    return 1;
  else if(x=='*' || x=='/' || x=='%' )
    return 2;
  else if(x=='^' )
    return 3;
  else
    return -1;
}

int main()
{
  int stk[1];
  int t=-1,i=0;
  char x;
  string s;
  s='('+s+')';
  getline(cin,s);
  int n=s.length();

  while(s[i]!='\0')
  {
    if(isalnum(s[i]))
      cout<<s[i];
    else if(s[i]=='(')
      push(stk,s[i],t);
    else if(s[i]==')')
    {
      while(x=pop(stk,t)!='(')
        cout<<x;
    }
    else
    {
      while(prop(stk[t])>=prop(s[i]))
        cout<<pop(stk,t);
      push(stk,s[i],t);
    }
    i++;
  }

  while(t!=-1)
    cout<<pop(stk,t);
}
