k = int(input())
r = list(map(int, input().split()))
p = set(r)

# stores the sum of all unique elements x total no of groups
a = sum(p)*k

# stores the sum of element in the list
b = sum(r)

# (a - b) = (k - 1)*captains_room_no
# prints the the difference of a and b divided by k-1
print((a-b)//(k-1))
