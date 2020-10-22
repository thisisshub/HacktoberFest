def angryProfessor(k, a):
    c=0
    while c < len(a) and k>0:
        if a[c] <= 0:
            k-=1
        c+=1
    print("NO" if k==0 else "YES")


if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        nk = input().split()

        n = int(nk[0])

        k = int(nk[1])

        a = list(map(int, input().rstrip().split()))

        angryProfessor(k, a)
