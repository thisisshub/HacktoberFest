def plusMinus(arr,n):
    c_p = c_n = zero = 0
    for i in range(n):
        if arr[i] > 0:
            c_p +=1
        if arr[i] < 0:
            c_n +=1
        if arr[i]==0:
            zero +=1
    return print(('%.6f'%(c_p/n)),('%.6f'%(c_n/n)),('%.6f'%(zero/n)),sep='\n')


if __name__ == '__main__':
    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr,n)
