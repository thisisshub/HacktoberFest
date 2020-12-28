from collections import Counter

n = int(input())

# storing all the words into a list
r = [input() for _ in range(n)]

# getting all the counts of words using counter
p = Counter(r)

print(len(p))
print(*p.values())
