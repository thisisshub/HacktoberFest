/*
Transpose of a row x column matrix
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
    vector<vector<int> >mat_tran(column,vector<int>(row));
    for(int i=0;i<column;i++)
        for(int j=0;j<row;j++)
            mat_tran[i][j]=mat[j][i];

    cout<<"Transpose of Matrix"<<endl;
    for(int i=0;i<column;i++)
    {
        for(int j=0;j<row;j++)
        {
            cout<<mat_tran[i][j]<<" ";
        }
        cout<<endl;
    }

    
    
}
