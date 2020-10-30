import math


def kaprekarNumbers(p, q):
    # c = list(str(int(math.pow(p,2))))
    # print("Yes" if int(c[0])+int(c[1])==p else "NO")
    for i in range(p,q+1):
        c = list(str(int(math.pow(i,2))))
        # print(c)
        if len(c)>1:
            if int(c[0]) + int(c[1]) == i:
                print(i)


if __name__ == '__main__':
    p = int(input())

    q = int(input())

    kaprekarNumbers(p, q)
