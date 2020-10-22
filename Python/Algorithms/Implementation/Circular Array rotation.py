def circularArrayRotation(a, k, queries):
    k = k%len(a)
    a =a[-k:] + a[:-k]
    for i in queries:
        print(a[i])


if __name__ == '__main__':
    nkq = input().split()

    n = int(nkq[0])

    k = int(nkq[1])

    q = int(nkq[2])

    a = list(map(int, input().rstrip().split()))

    queries = []

    for _ in range(q):
        queries_item = int(input())
        queries.append(queries_item)

    circularArrayRotation(a, k, queries)
