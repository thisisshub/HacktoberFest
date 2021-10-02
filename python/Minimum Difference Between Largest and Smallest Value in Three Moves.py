class Solution:
    def minDifference(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 4:
            return 0
        nums.sort()
        res = float('inf')
        for i in range(0,4):
            res = min(res,nums[n-1-3+i]- nums[i])
        
        return res
            
        

class Solution:
    def minDifference(self, nums: List[int]) -> int:
        nums = nums.sort()
        return min(b - a for a, b in zip(nums[:4], nums[-4:]))
