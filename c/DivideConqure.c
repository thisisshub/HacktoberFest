#include<stdio.h>
void checkIndex(int index,int arr[],int size);
void checkElement(int position,int arr[],int size);

int main(){

        int N;
        scanf("%d",&N);

        int A[N];

        for(int i = 0 ; i < N ; i++){

                scanf("%d",&A[i]);

        }

        checkIndex(0,A,N);
}

void checkIndex(int index,int arr[],int size){

        if(index == size){
                printf("\n");
                return;
        }

        else checkElement(index,arr,size);

}

void checkElement(int position,int arr[],int size){

        for(int i = position +1 ; i< size ; i++){
                if(arr[position]> arr[i]) printf("(%d,%d)",arr[position],arr[i]);
        }
        checkIndex(position +1 ,arr,size);

}