#include<iostream>
using namespace std;

void syym_diff(int [], int [], int, int);

int main()
{
    int x;
    cout<<"Enter the size of set U: ";
    cin>>x;
    int u[x];
    cout<<"Enter the elements of set U: ";
    for(int i = 0; i < x; i++)
    {
        cin>>u[i];
    }
     int a[10], b[10], m, n;
     label:
         cout<<"Enter the size of setA: ";
         cin>>m;
    if(m > x)
    {
        cout<<"Lesser than the Universal set"<<endl;
        goto label;
    }
    input:
        cout<<"Enter the elements of setA: ";
        for(int i = 0; i < m; i++)
        {
            cin>>a[i];
        }
        int c = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < x; j++)
            {
                if(a[i] == u[j])
                {
                    c++;
                }
            }
        }
        if(c != m)
        {
            cout<<"Not same elements in set and universal elements"<<endl;
            goto input;
        }
    label1:
        cout<<"Enter the elements of setB: ";
        cin>>n;
    if(n > x)
    {
        cout<<"Lesser than the Universal set"<<endl;
        goto label1;
    }
    input1:
        cout<<"Enter the elements of setB: ";
        for(int j = 0; j < n;j++)
        {
            cin>>b[j];
        }
        int d = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < x; j++)
            {
                if(b[i] == u[j])
                {
                    d++;
                }
            }
        }
        if(d != n)
        {
            cout<<"Not same elements in set and universal elements"<<endl;
            goto input1;
        }
    cout<<"Symmetric difference between sets is: ";
    syym_diff(a,b,m,n);
}

void syym_diff(int a[], int b[], int m, int n)
{
    int flag = 0;
    int c[10], k = 0;

    for(int i = 0; i < m; i++)
    {
        flag = 0;
        for(int j = 0; j < n; j++)
        {
            if(a[i] == b[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            cout<<a[i]<<" ";
        }
    }
    for(int j = 0; j < n; j++)
    {
        flag = 0;
        for(int i = 0; i < m; i++)
        {
            if(b[j] == a[i])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
           cout<<b[j]<<" ";
        }
    }
}
