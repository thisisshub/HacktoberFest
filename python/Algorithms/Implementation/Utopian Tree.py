def utopianTree(n):
    k=int(n/2)
    m= 1 if n % 2 == 0 else 2
    return 2 ** (k + m) - m


if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        n = int(input())

        result = utopianTree(n)

        print(result)
