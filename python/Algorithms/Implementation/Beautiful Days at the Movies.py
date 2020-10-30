def beautifulDays(i, j, k):
    c=0
    for x in range(i,j+1):
        if abs(x -int(str(x)[::-1])) %k==0:
            c+=1
    print(c)


if __name__ == '__main__':
    ijk = input().split()

    i = int(ijk[0])

    j = int(ijk[1])

    k = int(ijk[2])

    beautifulDays(i, j, k)