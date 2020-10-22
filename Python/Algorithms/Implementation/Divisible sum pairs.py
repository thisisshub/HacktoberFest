def divisibleSumPairs(n, k, ar):
    c=0
    for i in range(0,n):
        for j in range(1+i,len(ar)):
            if (ar[i]+ar[j]) % k==0:
                c+=1
    return c


if __name__ == '__main__':
    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    ar = list(map(int, input().rstrip().split()))

    result = divisibleSumPairs(n, k, ar)
    print(result)
