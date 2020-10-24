'''
Given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal than target.

Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:

Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)

'''

'''
1.This problem is a manipulation of Two sum problem.
2. In this problem, order of numbers of a subsequence doesn't matter as we just have to consider max and min of subsequence.Therefore, a subsequence from i to j in original array is equivalent to array having same elements and same minimum and maximum value. For e.g consider, nums = [3,7,6,5] and target = 10.For eg, In this a subsequence [3,7,6] is equivalent to subsequence [3,6,7] of [3,5,6,7]. Therefore, result of nums is equal to result of sorted[nums].
3. For each index "i" in sorted_nums, find maximum "j" such that sorted_nums[i] + sorted_nums[j] <= target and j >= i.
4. From i+1 to j, we can either pick or leave each element.
5. Therefore, res += 2**(j-i)
'''

class Solution:
    @staticmethod
    ''''function to find subsequences
    Time Complexity O(nlogn)
    Space Complexity O(1)
    '''
    def numSubseq(nums, target): 
        res = 0
        end = len(nums)-1
        nums.sort()
        for i in range(len(nums)):
            while nums[i] + nums[end] > target:
                if end > i:
                    end = end-1
                else:
                    return res % (10**(9)+7)
            res += pow(2, end - i)
        return res % (10**(9)+7)


# Driver Code
if __name__ == "__main__":
    nums = [3, 5, 6, 7]
    target = 9
    result = Solution.numSubseq(nums, target)
    print("total number of subsequence are = ", result)