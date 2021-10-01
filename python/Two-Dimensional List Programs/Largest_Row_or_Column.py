# Largest Row or Column
# For a given two-dimensional integer array/list of size (N x M), you need to find out which row or column has the largest sum(sum of all the elements in a row/column) amongst all the rows and columns.

# Note :
# If there are more than one rows/columns with maximum sum, consider the row/column that comes first. And if ith row and jth column has the same largest sum, consider the ith row as answer.

# Input Format :
# The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
# First line of each test case or query contains two integer values, 'N' and 'M', separated by a single space. They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.
# Second line onwards, the next 'N' lines or rows represent the ith row values.
# Each of the ith row constitutes 'M' column values separated by a single space.

# Output Format :
# For each test case, If row sum is maximum, then print: "row" <row_index> <row_sum>
# OR
# If column sum is maximum, then print: "column" <col_index> <col_sum>
# It will be printed in a single line separated by a single space between each piece of information.
# Output for every test case will be printed in a seperate line.


# Sample Input 1 :
# 1
# 2 2
# 1 1
# 1 1
# Sample Output 1 :
# row 0 2

# Sample Input 2 :
# 2
# 3 3
# 3 6 9
# 1 4 7
# 2 8 9
# 4 2
# 1 2
# 90 100
# 3 40
# -10 200
# Sample Output 2 :
# column 2 25
# column 1 342


def lar_sum(li , n , m):
    sum = 0
    max_sum = -1
    max_index = -1
    for i in range(n):
        for j in range(m):
            sum += li[i][j]
        if max_sum <sum:
            max_sum = sum
            max_index= i
    return max_sum,max_index

t = int(input())
for p in range(t):
    str = input().split()
    n,m = int(str[0]),int(str[1])
    li=[[int (j) for j in input().split()] for i in range(n)]
    lar_row_sum,lar_row_index = lar_sum(li,n,m)
    lar_col_sum,lar_col_index = lar_sum(li,m,n)
    if lar_row_sum >= lar_col_sum:
        print("row",lar_row_index,lar_row_sum)
    else:
        print("column",lar_col_index,lar_col_sum)