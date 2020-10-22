if __name__ == '__main__':
    n = int(input())

    arr = list(map(int, input().rstrip().split()))
    print(*arr[::-1],sep=' ')