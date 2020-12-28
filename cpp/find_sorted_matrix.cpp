/*
Check of a number exists in a sorted matrix or not
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int row,column;
    cin>>row>>column;
    vector<vector<int> >mat(row,vector<int>(column));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
            cin>>mat[i][j];
    }
    int num;
    cin>>num;
    if(num<mat[0][0] or num>mat[row-1][column-1])
    {
        cout<<"Number does not exist in the matrix"<<endl;
        return 0;
    }
    else
    {
        int start=0,end=column-1;
        while(start<row and end>=0)
        {
            if(num==mat[start][end])
            {
                cout<<"Number exists in the matrix"<<endl;
                return 0;
            }
            if(num<mat[start][end])
                end--;
            else
                start++;
        }
    }
  

    
    
}
