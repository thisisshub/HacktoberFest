def function(arr, i, j):
    pivot = i
    end = j
    while j >= i and j > pivot and i < end:
        if arr[i] >= arr[pivot]:
            i = i+1
        if arr[j] <= arr[pivot]:
            j = j-1
        if j > i and arr[i] < arr[pivot] and arr[j] > arr[pivot]:
            arr[i], arr[j] = arr[j], arr[i]
        # print(arr)
    arr[j], arr[pivot] = arr[pivot], arr[j]
    if j - 1 > pivot:
        function(arr, pivot, j - 1)
    if j + 1 < end:
        function(arr, j + 1, end)


if __name__ == "__main__":
    # arr=[1,4,2,6,10,7]
    # arr = [520, 601, 679, 540, 574, 634, 671, 575, 643, 538, 515, 584, 678, 524, 515, 575, 542, 639, 507, 663, 545, 641, 654, 617, 605, 697, 666, 507, 655]
    print("enter the size of the array ")
    n = int(input())
    print("enter the vaues in array")
    arr = []
    for _ in range(n):
        val = int(input())
        arr.append(val)
    arr.append(float('-inf'))
    function(arr, 0, len(arr) - 1)
    arr.pop()
    print(arr)