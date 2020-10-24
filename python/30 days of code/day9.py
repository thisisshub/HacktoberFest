def factorial(n):
    if n<=1:
        return n
    else:
        return n*factorial(n-1)


if __name__ == '__main__':
    n = int(input())
    print(factorial(n))
