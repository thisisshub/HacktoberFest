#include<iostream>
#include<string.h>

using namespace std;

int main()
{

    string str, rev="";

    cout<<"Enter the string"<<endl;
    getline(cin,str);

    int len= str.length();
    rev.resize(len);

    for (int i = 0, j=len-1; i <len; i++,j--)
    {
        rev[i]=str[j];
    }
    rev[len]='\0';
    if (str.compare(rev)==0||str[0]==rev[0]-32)
    {
        cout<<"The string is a palindrome";
    }
    else
    {
        cout<<"The string is not a palindrome";
    }
    return 0; 

}
