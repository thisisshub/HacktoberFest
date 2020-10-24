#include<stdio.h>

void toh(int n, int A, int B, int C)
{
    if (n>0)
    {
        toh(n-1,A,C,B);
        printf("Move disk from %d to %d\n",A,C);
        toh(n-1,B,A,C);
    }
    
}

int main()
{
    int x;
    printf("Enter the number of disks you want to insert\n");
    scanf("%d", &x);
    toh(x,1,2,3);
    return 0;
}
