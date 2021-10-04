#include <iostream>
#include <math.h>
using namespace std;

int main() {
	// your code goes here
	int t  , n , sum;
	scanf("%d",&t) ;
	while(t--) {
	    sum = 0 ;
	    scanf("%d",&n) ;
	    while(n!=0) {
	        sum = sum + (n%10) ;
	        n=n/10 ;
	    }
	    cout<<sum<<endl ;
	}
	
	return 0;
}
