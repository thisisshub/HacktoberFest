/*
Problem Statement(Maximum Sub-array sum):-
	You are given an array of length n, you have to find the maximum
	sum you can get by choosing a subarray and summing up its numbers
Solution(Kadane's Algorithm):-
	The main idea of this algorithm is to use two variables msf(maximum so far)
	and meh(maximum ending here) and updating meh by adding the	current number 
	to it, and updating msf by comparing it with meh, and if at any step meh
	becomes less than zero it can be reinitialized to zero meaning that a new
	subarray is starting from here.
Runtime Complexity:-
	O(n) where n is the length of the array
*/ 
#include<iostream> 
#include<vector>
#include<climits> 

using namespace std; 
  
int kadane(vector<int> &a) 
{ 
	int n=a.size(),msf=INT_MIN,meh=0;
  	
  	for(int i=0;i<n;i++)
  	{
  		meh+=a[i];
  		if(msf<meh)
  			msf=meh;
  		if(meh<0)
  			meh=0;
  	}
  	return msf; 
} 

int main() 
{ 
	cout<<"\nEnter the size of the array : ";
	int n;
	cin>>n;
	cout<<"\nEnter the elements of the array : ";
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	int ans=kadane(a);
	cout<<"\nMaximum Sub-array sum found in the array is : "<<ans<<endl;

	return 0;
}
