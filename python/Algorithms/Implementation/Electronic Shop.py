def getMoneySpent(keyboards, drives, b):
    a=[]
    for i in keyboards:
        for j in drives:
            if i+j<=b:
                a.append(i+j)
            else:
                a.append(-1)
    if max(a) <= b:
        print(max(a))
    else:
        print(-1)


if __name__ == '__main__':
    bnm = input().split()

    b = int(bnm[0])

    n = int(bnm[1])

    m = int(bnm[2])

    keyboards = list(map(int, input().rstrip().split()))

    drives = list(map(int, input().rstrip().split()))
    getMoneySpent(keyboards, drives, b)
