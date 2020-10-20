#include<stdio.h>

int main(){
    int a[100][100],b[100][100],c[100][100],row,column;

    // first martix
    printf("Enter the first matrix size : \n");
    scanf("%d %d",&row,&column);
    for ( int i = 0; i < row; i++)
    {
        for(int j=0 ;j<column;j++){
            scanf("%d",&a[i][j]);
        }
    }
    // second matrix
 printf("Enter the second matrix size : \n");
    scanf("%d %d",&row,&column);
    for ( int i = 0; i < row; i++)
    {
        for(int j=0 ;j<column;j++){
            scanf("%d",&b[i][j]);
        }
    }


// multiplication
 
    printf("The multiplied matrix is : \n");
    int sum = 0; 
    for ( int i = 0; i < row; i++)
    { 
        for(int j=0 ;j<column;j++){
        sum=0;
        for ( int k = 0; k < row; k++)
        {
        
        sum+=a[i][k]*b[k][j];
        
        }
        c[i][j]=sum;
         printf("%d ",c[i][j]);
        }
        printf("\n");
        
    }

    return 0;
}