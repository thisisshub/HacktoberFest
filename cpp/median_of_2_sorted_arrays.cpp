/* 4. Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
*/
#include<bits/stdc++.h>

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2,nums1);
        int n1 = nums1.size(), n2 = nums2.size();
        int low = 0, high = n1;
        while(low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = (n1 + n2 + 1)/2 - cut1; 
            
            int l1 = cut1 == 0? INT_MIN : nums1[cut1-1];
            int l2 = cut2 == 0? INT_MIN : nums2[cut2-1];
            
            int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];
            
            if(l1 <= r2 && l2 <= r1) {
                if((n1 + n2) % 2 == 0) {
                    return (max(l1,l2) + min(r1,r2)) / 2.0;
                } else
                    return max(l1, l2);
            }
            else if(l1 > r2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }
        return 0.0;
    }