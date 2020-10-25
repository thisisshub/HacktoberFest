#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int n) {
        --n;
        vector <int> prime;
        vector<bool> isprime(n+1, true);
        vector<int> smallest_prime_factor(n+1,0);
        
        for(int i = 2 ; i <= n ; ++i) {
            
            if(isprime[i]){
                prime.push_back(i);
                smallest_prime_factor[i] = i;
            }
            
            for(int j = 0 ; j < prime.size() && i*prime[j] <= n && prime[j] <= smallest_prime_factor[i] ; ++j) {
                isprime[i*prime[j]] = false;
                smallest_prime_factor[i*prime[j]] = prime[j];
            }
        }
        return prime.size();
    }


int main () {
	int turn;
	cin >> turn;
	while (turn --) {
		int lim;
		cin >> lim;
		int res = countPrimes(lim);
		cout << res;
	}
	return 0;
}
