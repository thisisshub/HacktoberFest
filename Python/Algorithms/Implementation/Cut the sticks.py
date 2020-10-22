from collections import Counter


def cutTheSticks(arr):
    l=len(arr)
    c = []
    for k,v in sorted(Counter(arr).items()):
        c.append(l)
        l-=v
    for i in c : print(i)


if __name__ == '__main__':
    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    cutTheSticks(arr)
