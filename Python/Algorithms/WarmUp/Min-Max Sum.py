def miniMaxSum(arr):
    maxi = 0
    mini = 0
    arr.sort()
    print(max(arr))
    for i in range(len(arr)-1):
        mini += arr[i]
    for j in range(1,len(arr)):
        maxi +=arr[j]
    print(mini,maxi)


if __name__ == '__main__':
    arr = list(map(int, input().rstrip().split()))

    miniMaxSum(arr)
