
def printSpiralOrder(mat):
 
    # base case
    if not mat or not len(mat):
        return
 
    top = left = 0
    bottom = len(mat) - 1
    right = len(mat[0]) - 1
 
    while True:
        if left > right:
            break
 
        # print top row
        for i in range(left, right + 1):
            print(mat[top][i], end=' ')
        top = top + 1
 
        if top > bottom:
            break
 
        # print right column
        for i in range(top, bottom + 1):
            print(mat[i][right], end=' ')
        right = right - 1
 
        if left > right:
            break
 
        # print bottom row
        for i in range(right, left - 1, -1):
            print(mat[bottom][i], end=' ')
        bottom = bottom - 1
 
        if top > bottom:
            break
 
        # print left column
        for i in range(bottom, top - 1, -1):
            print(mat[i][left], end=' ')
        left = left + 1
 
 
if __name__ == '__main__':
 
    mat = [
        [1, 2, 3, 4, 5],
        [16, 17, 18, 19, 6],
        [15, 24, 25, 20, 7],
        [14, 23, 22, 21, 8],
        [13, 12, 11, 10, 9]
    ]
 
    printSpiralOrder(mat)
