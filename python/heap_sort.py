def heapify(arr,n,i):
    l=2*i+1
    r=2*i+2

    if l<n and arr[l] > arr[i]:
        largest = l
    else:
        largest = i
    
    if r<n and arr[r]>arr[largest]:
        largest = r

    if largest != i:
        arr[i],arr[largest] = arr[largest],arr[i]
        heapify(arr,n,largest)

def heapSort(arr):
    n=len(arr)
    for i in range(n,-1,-1):
        heapify(arr,n,i)
    for i in range(n-1,0,-1):
        arr[0],arr[i] = arr[i],arr[0]
        heapify(arr,i,0)

arr=[33,35,42,10,7,8,14,19,48]
heapSort(arr)
print(arr)
