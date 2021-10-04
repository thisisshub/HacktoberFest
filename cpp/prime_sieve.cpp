#include<bits/stdc++.h>
using namespace std;

void sieve(int n)
{
    vector<bool>isprime(n+1,true);
    for(int i=2;i*i<=n;i++)//this is for checking prime
      {
          if(isprime[i]==true)
          {
              for(int j=2*i;j<=n;j=j+i)//this marks multiple of prime as false
                isprime[j]=false;
          }
      }
    for(int i=2;i<=n;i++)// this prints the array which are still marked true
     {
         if(isprime[i]==true)
         cout<<i<<" ";
     }    

}

//Optimized approach 
//Here we are not going to check for 10,15,20 we directly start from 25 and this save some
// time and code also become shorter
void prime_sieve(int n)
{
    vector<bool> isprime(n+1,true);
    for(int i=2;i<=n;i++)
    {
        if(isprime[i]==true)//here we are saving one traversal as we print the number as soon as
            cout<<i<<" ";//its marked as true

        // instead of using 2*i here we will be using i*i            
        
        for(int j=i*i;j<=n;j=j+i)//this loops marks the multiple of prime numbers as false
            isprime[j]=false;
    }
}

int main()
{
    int n;
    cin>>n;
    sieve(n);
 return 0;   
}