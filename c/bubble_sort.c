#include <stdio.h>
#include <stdlib.h>

int main(){
int N;
printf("Enter the number of elements in the array\n");
scanf("%d",&N);
int *arr=malloc(N*sizeof(*arr));
printf("\nEnter the elemnts of the array\n");
for(int i=0;i<N;i++){
  scanf("%d",&arr[i]);
}
printf("\nOriginal Array\n");
for(int i=0;i<N;i++){
  printf("%d ",arr[i]);
}
int temp;
for(int i=0;i<N-1;i++){
  for(int j=0;j<N-i-1;j++){
    if(arr[j]>arr[j+1]){
      temp=arr[j];
      arr[j]=arr[j+1];
      arr[j+1]=temp;
    }
  }
}
printf("\nSorted Array\n");
for(int i=0;i<N;i++){
  printf("%d ",arr[i]);
}
}