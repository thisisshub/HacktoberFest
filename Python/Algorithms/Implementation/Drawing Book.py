def pageCount(n, p):
    print(min(p//2,n//2-p//2))


if __name__ == '__main__':
    n = int(input())

    p = int(input())

    pageCount(n, p)
