# Example

# Input

# Input string: codeforwin
# Output

# Frequency of all characters in the given string:
# 'c' = 1
# 'd' = 1
# 'e' = 1
# 'f' = 1
# 'i' = 1
# 'n' = 1
# 'o' = 2
# 'r' = 1
# 'w' = 1

string = "codeforwin"

frq = [0]*26

for i in string:
	frq[ord(i)-97]+=1


for i in string:
	print(i,'=',frq[ord(i)-97])

