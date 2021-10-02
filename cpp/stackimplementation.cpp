#include<bits/stdc++.h>
using namespace std;
class A
{
   
    int* arr;
    int n;
    int top;
    public:
    A()
    {
        arr=new int[n];
        top=-1;
    }

void push(int val)
{
    if(top==(n-1))
    {
        cout<<"STACK OVERFLOWED"<<endl;
        return;
    }
    top=top+1;
    arr[top]=val;
    
}
void pop()
{
    if(top==-1)
    {
        cout<<"STACK UNDERFLOW:"<<endl;
    }
    top=top-1;
}
int Top()
{
    if(top==-1)
    {
        cout<<"STACK IS EMPTY"<<endl;
        return -1;
    }
    return arr[top];
}
bool empty()
{
    if(top==-1)
    return true;
    else 
    return false;
}
};
int main()
{
    A st;
    int n;
    cin>>n;
   

    for(int i=0;i<n;i++)
    {
        int element;
        cin>>element;
        st.push(element);
    }
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    
}
