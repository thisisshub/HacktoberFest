// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
   int x=10;
   int*px=&x,**ppx=&px;
   **ppx=x+(**ppx)+(-(*px))+x;
   printf("%d",x);
}
