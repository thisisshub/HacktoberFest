"""
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
"""
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return 0
        s=0
        e=(len(matrix)*len(matrix[0]))-1
        while(s<=e):
            mid=(s+e)//2 
            r=mid//len(matrix[0])
            c=mid%len(matrix[0])
            if matrix[r][c]==target:
                return 1
            elif matrix[r][c]>target:
                e=mid-1
            else:
                s=mid+1
        return 0
