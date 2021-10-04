#include <stdio.h>
#include <math.h>
void primecheck(int *n) ;
int main () {
int n ;
printf("enter the number :") ;
scanf("%d",&n) ;
primecheck(&n) ;

return 0 ;
}

void primecheck(int *n) {
    int j , flag = 0 ;
	for(j=2 ; j <= sqrt(*n); j++) {
		if(*n%j==0) {
			flag = 1 ;
			break ;
		}
	}
    if(flag==0) {
	    printf("\n%d is a prime number",(*n)) ;
	}
	else {
	    printf("\n%d is not a prime number\n",*n) ;
	}
}