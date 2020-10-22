def jumpingOnClouds(c, k):
    e=100
    i=k%n
    e-=c[i]*2+1
    print(e)
    while i!=0:
        i=(i+k)%n
        e-=c[i]*2+1
    print(e)


if __name__ == '__main__':
    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    c = list(map(int, input().rstrip().split()))

    jumpingOnClouds(c, k)
