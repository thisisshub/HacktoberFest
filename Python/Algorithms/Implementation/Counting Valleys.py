def countingValleys(n, s):
    h=0
    c=0
    for i in s:
        if i =="U":
            h+=1
            if h==0:
                c+=1
        else:
            h-=1
    print(c)


if __name__ == '__main__':
    n = int(input())

    s = input()

    countingValleys(n, s)