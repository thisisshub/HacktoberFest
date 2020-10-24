sum_g = 4

ar = [1,1,1,1]
n = len(ar)

dp =[[0 for i in range(sum_g+1)] for i in range(n+1)]

for i in range(n+1):
	dp[i][0] = 1 

for i in range(1, n+1):
	for j in range(1, sum_g+1):

		if ar[i-1]<=j:
			dp[i][j] = dp[i-1][j-ar[i-1]] + dp[i-1][j]   # dp[i-1][j-ar[i-1]] = number of ways to build sum j including i 
														 # dp[i-1][j] = number of ways to build sum j excluding i
														 # add them both to get total ways
		else:
			dp[i][j] = dp[i-1][j]

for i in range(n+1):
	print(dp[i])

print(dp[-1][-1])
