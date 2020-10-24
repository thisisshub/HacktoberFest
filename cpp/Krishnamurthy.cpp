/*  PROGRAM AUTHOR : SAYANTAN BOSE
    PROGRAM DETAILS : A Krishnamurthy number is a number whose sum of the factorial of digits is equal to the number itself. For example 145, 1! + 4!
*/
// C++ program to check if a number 
// is a krishnamurthy number 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to calculate the factorial of any number 
int factorial(int n) 
{ 
    int fact = 1; 
    while (n != 0) { 
        fact = fact * n; 
        n--; 
    } 
    return fact; 
} 
  
// function to Check if number is krishnamurthy 
bool isKrishnamurthy(int n) 
{ 
    int sum = 0; 
  
    int temp = n; 
    while (temp != 0) { 
        // calculate factorial of last digit 
        // of temp and add it to sum 
        sum += factorial(temp % 10); 
  
        // replace value of temp by temp/10 
        temp = temp / 10; 
    } 
  
    // Check if number is krishnamurthy 
    return (sum == n); 
} 
  
// Driver code 
int main() 
{ 
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
     if (isKrishnamurthy(n)) 
        cout << "YES"; 
    else
        cout << "NO"; 
    return 0; 
} 
