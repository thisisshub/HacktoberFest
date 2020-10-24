import math
def prime(n):
    if n==1:
        return print("Not prime")
    sq = int(math.sqrt(n))
    for i in range(2,sq+1):
        if n % i == 0:
            return print("Not prime")
    return print("Prime")


t = int(input())
for _ in range(t):
    prime(int(input()))
