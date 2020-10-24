/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 
 */
 
 class Solution(object):
    def twoSum(self, nums, target):
		hash_table = {}
		for i in range(len(nums)):
			complement = target - nums[i]
			if complement not in hash_table:
				hash_table[nums[i]] = i
			else:
				return [hash_table[complement], i]
