"""
This question going to use Brute Force.
"""


def solve(x,y):
    max_bitwise = 0
    for i in range(1,x+1):
        for j in range(1,i):
            bit = i&j
            if max_bitwise < bit < y:
                max_bitwise = bit
                if max_bitwise == y -1:
                    return print(max_bitwise)
    return print(max_bitwise)


t= int(input())
for _ in range(t):
    x,y = map(int,input().split(' '))
    solve(x,y)