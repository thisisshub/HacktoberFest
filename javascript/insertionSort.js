let insertionSort = (arr) => {
    let i,j,ele;
    for(i = 1;i<arr.length;i++){
        j = i - 1;
        ele = arr[i];
        while(j>=0 && arr[j]>ele){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = ele;
    }
}
let a = [2,1,6,4,7,5]
insertionSort(a);
console.log(a);