//A C program to find whether the given string is Lapindrome or not.

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
 int T,flag;
 scanf("%d",&T);
 char ch[1001];
 int a[26],b[26];
  while(T--)
  {
    scanf("%s",ch);
    flag=1;
    for(int i=0;i<26;i++){
     a[i]=0;
     b[i]=0;
    }
    for(int i=0;i<strlen(ch)/2;i++)
    {
        a[ch[i]-97]++;
        b[ch[strlen(ch)-i-1]-97]++;
    }
    for(int i=0;i<26;i++)
    {
        if(a[i]!=b[i])
        {
            flag=0;
            break;
        }
    }
    if(flag==0)
      printf("NO\n");
      else
      printf("YES\n");
  }
    return 0;
}