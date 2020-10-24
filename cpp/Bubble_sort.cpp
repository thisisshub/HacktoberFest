// Bubble sort Time complexity O(n^2)
void bubble_Sort(int arr[],int n){
    bool swapped;
    for(int i = 0 ; i < n - 1 ; i++ )
    {
        swapped=false;
        for( int j = 0 ; j < n - i - 1 ; j++ ){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(swapped==false) //if no swapping takes place in the entire iteration then the array is sorted.
        break;
    }
}
// Function to swap the values of the array, part of bubble sort
void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
//Function to print the array after sorting
void printArray(int arr[],int n){
    for( int i = 0; i < n; i ++){
        cout<<arr[i]<<" ";
    } 
}
