def birthday(s, d, m):
    c=0
    sum=0
    for i in range(0,len(s)):
        sum += s[i]
        if i >= m-1:
            if sum == d:
                c += 1
            sum -= s[i-(m-1)]
    return print(c)


if __name__ == '__main__':

    n = int(input().strip())

    s = list(map(int, input().rstrip().split()))

    dm = input().rstrip().split()

    d = int(dm[0])

    m = int(dm[1])

    birthday(s, d, m)
