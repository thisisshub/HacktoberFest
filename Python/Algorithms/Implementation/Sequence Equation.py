def permutationEquation(p):
    maxi = max(p)
    mini = min(p)
    a = []
    for i in range(mini,maxi+1):
        a.append(p.index(p.index(i)+1)+1)
    for _ in a:
        print(_)


if __name__ == '__main__':
    n = int(input())

    p = list(map(int, input().rstrip().split()))
    permutationEquation(p)
