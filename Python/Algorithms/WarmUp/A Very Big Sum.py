def aVeryBigSum(ar):
    s = 0
    for i in range(len(ar)):
        s+=ar[i]
    return s


if __name__ == '__main__':
    ar_count = int(input())

    ar = list(map(int, input().rstrip().split()))
    result = aVeryBigSum(ar)
    print(result)