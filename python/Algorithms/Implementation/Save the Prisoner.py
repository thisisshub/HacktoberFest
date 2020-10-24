def saveThePrisoner(n, m, s):
    if (m+s-1)%n==0:
        print(n)
    else:
        print((m+s-1)%n)


if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        nms = input().split()

        n = int(nms[0])

        m = int(nms[1])

        s = int(nms[2])

        saveThePrisoner(n, m, s)

