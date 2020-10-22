def sockMerchant(n, ar):
    c={}
    s=0
    for i in ar:
        if i in c:
            c[i]+=1
        else:
            c[i]=1
    for x in c:
        if c[x]%2==0:
            s+=c[x]/2
        elif (c[x]-1)%2==0:
            s+=(c[x]-1)/2
    print(int(s))


if __name__ == '__main__':
    n = int(input())

    ar = list(map(int, input().rstrip().split()))

    sockMerchant(n, ar)