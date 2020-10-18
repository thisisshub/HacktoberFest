def maxHeap(arr, i):
    if i < len(arr):
        # v1 = v2 = -1
        if (i * 2) + 1 < len(arr):
            if arr[i] < arr[(i * 2) + 1]:
                arr[i], arr[(i * 2) + 1] = arr[(i * 2) + 1], arr[i]
        if (i * 2) + 2 < len(arr):
            if arr[i] < arr[(i * 2) + 2]:
                arr[i], arr[(i * 2) + 2] = arr[(i * 2) + 2], arr[i]
        maxHeap(arr, (i * 2) + 1)
        maxHeap(arr, (i * 2) + 2)


def function(arr):
    sr = []
    for i in range(len(arr)):
        for _ in range(len(arr)):
            maxHeap(arr, 0)
        sr.append(arr.pop(0))
    print(sr)
        

if __name__ == "__main__":
    print("enter the size of the array ")
    size = int(input())
    arr = []
    print("enter the data to the array ")
    for _ in range(size):
        val = int(input())
        arr.append(val)
    function(arr)