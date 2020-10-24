def birthdayCakeCandles(ar):
    c=0
    arr = max(ar)
    for i in range(len(ar)):
        if arr == ar[i]:
            c+=1
    return c


if __name__ == '__main__':
    ar_count = int(input())

    ar = list(map(int, input().rstrip().split()))

    result = birthdayCakeCandles(ar)
    print(result)
