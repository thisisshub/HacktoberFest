def jumpingOnClouds(c):
    i=0
    s=-1
    while i < len(c):
        if i < len(c)-2 and c[i+2]==0: i+=1
        s+=1
        i+=1
    print(s)


if __name__ == '__main__':
    n = int(input())

    c = list(map(int, input().rstrip().split()))

    jumpingOnClouds(c)



