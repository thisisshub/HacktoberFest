void insertion_Sort(int arr[], int n){
    int key,i,j;
    for( i = 1 ; i < n ; i ++){
        key=arr[i];
        j=i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
//Function to print the array after sorting
void printArray(int arr[],int n){
    for( int i = 0; i < n; i ++){
        cout<<arr[i]<<" ";
    } 
}

