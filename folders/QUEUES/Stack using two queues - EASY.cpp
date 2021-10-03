/*
Stack using two queues 

Easy Accuracy: 40.49% Submissions: 71675 Points: 2
Implement a Stack using two queues q1 and q2.

Example 1:

Input:
push(2)
push(3)
pop()
push(4)
pop()
Output: 3 4
Explanation:
push(2) the stack will be {2}
push(3) the stack will be {2 3}
pop()   poped element will be 3 the 
        stack will be {2}
push(4) the stack will be {2 4}
pop()   poped element will be 4  
Example 2:

Input:
push(2)
pop()
pop()
push(3)
Output: 2 -1
Your Task:

Since this is a function problem, you don't need to take inputs. You are required to complete the two methods push() which takes an integer 'x' as 
input denoting the element to be pushed into the stack and pop() which returns the integer poped out from the stack(-1 if the stack is empty).

Expected Time Complexity: O(1) for push() and O(N) for pop() (or vice-versa).
Expected Auxiliary Space: O(1) for both push() and pop().

Constraints:
1 <= Number of queries <= 100
1 <= values of the stack <= 100
*/

#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }else if(QueryType==2){
            cout<<qs->pop()<<" ";

        }
        }
        cout<<endl;
    }
}
// } Driver Code Ends
/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

/* The method push to push element into the stack */
void QueueStack :: push(int x)
{
        // Your Code
        q1.push(x);
}
/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
        // Your Code       
        
        if(q1.empty()){
            return -1;
        }
        else{
            
            // Transfer from q1 to q2 till only 1 element left
            while(q1.size()!=1){
                int ele=q1.front();
                q1.pop();
                q2.push(ele);
            }
            // Last element left is to be popped
            int elementDeleted=q1.front();
            q1.pop();
            
            // Swap q1 and q2
            swap(q1,q2);
            
            return elementDeleted;
            
        }
}

