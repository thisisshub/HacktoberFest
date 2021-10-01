#include<iostream>
using namespace std;
int main()
{
    int num, i, flag=0;
    cout<<"Enter a Number to check whether prime or not : ";
    cin>>num;
    for(i=2; i<num; i++)
    {
        if(num%i==0)
        {
            flag++;
            break;
        }
    }
    if(flag==0)
        cout<<num<<" is a Prime Number";
    else
        cout<<num << " is not a Prime Number";
    cout<<endl;
    return 0;
}