'''
Given an unsorted integer array nums, find the smallest missing positive integer.

Follow up: Could you implement an algorithm that runs in O(n) time and uses constant extra space.?

Example 1:

Input: nums = [1,2,0]
Output: 3
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1

'''

'''
There will be two cases:
1) In 1st case, there will be no missing integer and answer will be n+1

2) In 2nd case, there will be mising positive integer.

We have to observe that our answer in 2nd case will be
in the range of 1 to n.
Now, before proceeding further we should make all values greater than n and val < 0 equal to n+1(because they are not in our range).

Now, we can treat each index as hash(1 eqv idx 0). If a number  exist in array, we make value at idx = number-1 negative.

In next traversal, if we find any number[i] > 0, we can conclude that the number with idx+1 doesn't exist.
even after this if we are unable to find then return n+1

'''


class Solution:
    
    '''
    Time Complexity O(n)
    Space Complexity O(1)
    '''
    @staticmethod
    def firstMissingPositive(nums):
        n = len(nums)
        for i in range(len(nums)):
            if (nums[i] <= 0) or (nums[i] > n):
                nums[i] = n+1
        #all numbers in range n+1
        #making index of corresponding nums to negative
        for i in range(len(nums)):
            num = abs(nums[i])
            if num > n:
                continue
            #making 0 indexed
            num-=1
            nums[num] = -abs(nums[num])
        #next traversal
        for i in range(len(nums)):
            if nums[i] > 0:
                return i+1
        return n+1


# Driver Code
if __name__ == "__main__":
    nums = [3, 4, -1, 1]
    result = Solution.firstMissingPositive(nums)
    print("Result = ", result)