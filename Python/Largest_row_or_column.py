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