def diagonalDifference(arr,n):
    left = 0
    right = 0
    for i in range(n):
        left += arr[i][i]
        right += arr[i][n - i - 1]
    return abs(left - right)


if __name__ == '__main__':
    n = int(input().strip())

    arr = []

    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))

    result = diagonalDifference(arr,n)
    print(result)
