from itertools import permutations


def nonDivisibleSubset(k, s):
    c = list(permutations(s,2))
    for _ in c: print(_)
    a = list(map(sum, c))
    print(a)
    b=0
    for i in a:
        if i%k==0:
            b+=1
    print(b)


if __name__ == '__main__':
    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    k = int(first_multiple_input[1])

    s = list(map(int, input().rstrip().split()))

    nonDivisibleSubset(k, s)
