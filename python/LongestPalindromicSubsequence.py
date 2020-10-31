import numpy as np

def LongestPalindromicSubsequence(str):
	n = len(str)
	T = np.zeros((n, n))
	for i in range(n):
		T[i, i] = 1
	for k in range(1, n):
		i = 0
		j = k
		while (j < n):
			if str[i] == str[j]:
				T[i,j] = 2 + T[i + 1, j - 1]
			else:
				T[i,j] = max(T[i, j-1], T[i+1, j])

			i += 1
			j += 1
	print(T)
	return (T[0,n-1])

print(LongestPalindromicSubsequence("racecar"))

# T = np.arange(16)
# T = T.reshape(4,4)
# print(T)
# n = 4

# for k in range(0, n):
# 	i = 0
# 	j = k
# 	while (j < n):
# 		print(T[i,j])
# 		i+=1
# 		j+=1
# [0, 1], [1, 2] [2, 3] ... / [0, 2], [1, 2], [2, 3] ... / [0, 3], [1, 4] ...
