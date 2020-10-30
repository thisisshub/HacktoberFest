#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a;
    cin>>a;
    int c=1;
    int s=1;

    for ( int i = 0 ; i<a.length()-1;i++)
    {
        while(a[i]==a[i+1])
        {
            c++;
            i++;
            
        }
        if(c>s){
            c=s;
        }
        
        

    }
    cout<<s;

}