def findDigits(n):
    # a= [str(n).replace('0','')]
    digit = [int(i)for i in str(n).replace('0','')]
    c=0
    for j in range(len(digit)):
        if n % digit[j]==0:
            c+=1
    print(c)


if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        n = int(input())

        findDigits(n)
