/* Minimum Cost for Joining Ropes */
/*
    Given a rope that has been broken into N parts,
    The task is to join the rope into 1 rope back.
    Given condition : Cost of joining two part = sum of length of both parts
    
    Requirement:    Minimum Cost to join the ropes
    Approach : Greedy + Heap
*/

#include <bits/stdc++.h>

using namespace std;

int main() 
{  
    int n = 5;  // size of array
    int pieces[n] = {1, 2, 3, 4, 5};
    int minCost = 0;

    // min Heap
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++)
        pq.push(pieces[i]);

    while(pq.size() != 1)
    {
        // taking out 2 elements - smallest pieces
        int p1 = pq.top();
        pq.pop();
        int p2 = pq.top();
        pq.pop();

        // adding their lenght to the cost
        minCost += p1 + p2;

        // pushing back the added length to the heap
        pq.push(p1 + p2);
    }
    // final answer
    cout<<minCost;
    return 0;
}
