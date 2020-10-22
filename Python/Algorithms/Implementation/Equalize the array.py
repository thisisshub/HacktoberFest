def equalizeArray(arr):
    print(len(arr)-max([arr.count(i)for i in arr]))


if __name__ == '__main__':
    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    equalizeArray(arr)
