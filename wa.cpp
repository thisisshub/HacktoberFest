#include <iostream>

using namespace std;

int main(void)
{   
    long long n;

    
    cin>>n;
    cout<<n<<" ";
    while(n!=1 && n>=1)
    {
        if ( n % 2 == 0)
        {
            n /= 2;
            cout<<n<<" ";
        }
        else
        {
            n = n * 3 + 1;
            cout<<n<<" ";
        }
        
    }

return 0;
    
}