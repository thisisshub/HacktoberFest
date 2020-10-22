def get_sum(arr,i,j):
    sum = 0
    sum += arr[i-1][j-1]
    sum += arr[i-1][j]
    sum += arr[i - 1][j+1]
    sum += arr[i][j]
    sum += arr[i+1][j-1]
    sum += arr[i+1][j]
    sum += arr[i+1][j+1]
    return sum


if __name__ == '__main__':
    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

max_sum = -63
for i in range(1,5):
    for j in range(1,5):
        current = get_sum(arr,i,j)
        if current > max_sum:
            max_sum = current
print(max_sum)