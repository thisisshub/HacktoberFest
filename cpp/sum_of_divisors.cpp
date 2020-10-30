#include<bits/stdc++.h>
using namespace std;

int mod = 1000000007;

// Functions returns sum
// of numbers from 1 to n
int linearSum(int n)
{
	return (n * (n + 1) / 2) % mod;
}

// Functions returns sum
// of numbers from a+1 to b
int rangeSum(int b, int a)
{
	return (linearSum(b) - 
			linearSum(a)) % mod;
}

// Function returns total
// sum of divisors
int totalSum(int n)
{
	
	// Stores total sum
	int result = 0;
	int i = 1;

	// Finding numbers and
	//its occurence
	while(true)
	{
		
		// Sum of product of each
		// number and its occurence
		result += rangeSum(n / i, n / (i + 1)) * 
						(i % mod) % mod;
		
		result %= mod;
		
		if (i == n)
			break;
			
		i = n / (n / (i + 1));
	} 
	return result;
}	 

// Driver code
int main()
{
	int N;
    cout<<"ENTER THE NUMBER UPTO WHICH YOU WANT THE SUM OF ALL DIVISORS:";
    cin>>N;
    cout<<"The sum of all divisors from 1 to "<<N<<"is =";
	cout << totalSum(N) << endl;
    cout<<"ENTER THE NUMBER UPTO WHICH YOU WANT THE SUM OF ALL DIVISORS:";
    cin>>N;
	cout << totalSum(N) << endl;
    cout<<"The sum of all divisors from 1 to "<<N<<"is =";

	return 0;
}
