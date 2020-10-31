/*
Subtraction of two matrices
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int row,column;
    cin>>row>>column;
    vector<vector<int> >mat1(row,vector<int>(column));
    vector<vector<int> >mat2(row,vector<int>(column));
    vector<vector<int> >mat3(row,vector<int>(column));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
            cin>>mat1[i][j];
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
            cin>>mat2[i][j];
    }
    for(int i=0;i<row;i++)
        for(int j=0;j<column;j++)
            mat3[i][j]=mat1[i][j]-mat2[i][j];
    cout<<"Subtraction of matrix is: "<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cout<<mat3[i][j]<<" ";
        }
        cout<<endl;
    }

    
  

    
    
}
