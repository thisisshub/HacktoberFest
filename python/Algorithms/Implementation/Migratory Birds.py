def migratoryBirds(arr):
    m = [4,3,2,1,0]
    for i in arr:
        m[i-1] += 10
    print(5-max(m)%10)


if __name__ == '__main__':
    arr_count = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    migratoryBirds(arr)
