import math


def extraLongFactorials(n):
    return math.factorial(n)


if __name__ == '__main__':
    n = int(input())

    result = extraLongFactorials(n)
    print(result)
