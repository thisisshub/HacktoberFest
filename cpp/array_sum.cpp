#include<iostream>

using namespace std;

int main(){
	int A[]={1,2,3,4,5};
	int sum=0;
	for(auto x:A){
		sum+=x;
	};
	cout<<sum;
	return 0;
}

