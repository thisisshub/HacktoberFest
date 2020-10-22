def pickingNumbers(a):
    maxi = 0
    for i in a:
        c=a.count(i)
        d=a.count(i-1)
        c=c+d
        if c> maxi:
            maxi =c
    print(maxi)


if __name__ == '__main__':
    n = int(input().strip())

    a = list(map(int, input().rstrip().split()))

    pickingNumbers(a)