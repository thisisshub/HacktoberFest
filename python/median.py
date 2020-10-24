/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

Follow up: The overall run time complexity should be O(log (m+n)).

 
 */
 
 class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        sorted_array = sorted(nums1+nums2)
        length = len(sorted_array)
        half = int(length/2)
        if length%2==0:
            out = (sorted_array[half-1] + sorted_array[half])/2
        else:
            out = sorted_array[half]
            
        return out
