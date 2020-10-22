def simpleArraySum(ar):
    sum = 0
    for i in range(len(ar)):
        sum+=ar[i]
    return sum


if __name__ == '__main__':

    ar_count = int(input())

    ar = list(map(int, input().rstrip().split()))

    result = simpleArraySum(ar)
    print(result)
