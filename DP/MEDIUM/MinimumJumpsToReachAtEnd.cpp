//QUESTION STATEMENT:
// Given an array of integers where each element represents the max number of steps that can be made forward from that element. 
//Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, they cannot move through
//that element. If the end isn’t reachable, return -1.

//TEST CASE:
// Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
// Output: 3 (1-> 3 -> 8 -> 9)
// Explanation: Jump from 1st element 
// to 2nd element as there is only 1 step, 
// now there are three options 5, 8 or 9. 
// If 8 or 9 is chosen then the end node 9 
// can be reached. So 3 jumps are made.

// Input:  arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
// Output: 10
// Explanation: In every step a jump 
// is needed so the count of jumps is 10.


//CPP CODE(DP SOLUTION):

#include <bits/stdc++.h>
using namespace std;

int min(int x, int y) { return (x < y) ? x : y; }

int minJumps(int arr[], int n)
{
    int* jumps = new int[n];
    int i, j;

    if (n == 0 || arr[0] == 0)
        return INT_MAX;

    jumps[0] = 0;

    for (i = 1; i < n; i++) {
        jumps[i] = INT_MAX;
        for (j = 0; j < i; j++) {
            if (i <= j + arr[j] && jumps[j] != INT_MAX) {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }
    return jumps[n - 1];
}

int main()
{
    int arr[] = { 1, 3, 6, 1, 0, 9 };
    int size = sizeof(arr) / sizeof(int);
    cout << "Minimum number of jumps to reach end is "
         << minJumps(arr, size);
    return 0;
}
