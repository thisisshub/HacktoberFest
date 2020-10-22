def countApplesAndOranges(s, t, a, b, apples, oranges):
    sum_apples = []
    sum_orange = []
    count_apples = 0
    count_orange = 0
    for i in range(len(apples)):
        sum_apples.append(apples[i]+a)
    for j in range(len(oranges)):
        sum_orange.append(oranges[j]+b)
    for x in range(len(sum_apples)):
        if s <= sum_apples[x] <= t:
            count_apples +=1
    for y in range(len(sum_orange)):
        if s <= sum_orange[y] <= t:
            count_orange +=1
    print(count_apples,count_orange, sep='\n')


if __name__ == '__main__':
    st = input().split()

    s = int(st[0])

    t = int(st[1])

    ab = input().split()

    a = int(ab[0])

    b = int(ab[1])

    mn = input().split()

    m = int(mn[0])

    n = int(mn[1])

    apples = list(map(int, input().rstrip().split()))

    oranges = list(map(int, input().rstrip().split()))

    countApplesAndOranges(s, t, a, b, apples, oranges)
