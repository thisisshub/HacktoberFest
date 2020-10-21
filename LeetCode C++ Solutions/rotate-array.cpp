/**
 * Author: Siddhant Pandya
 * Problem: 189. Rotate Array
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        vector<int> arr(nums.size());
        int i=nums.size()-k,y=0;
        
        for(int x=i;x<nums.size();x++)
        {
            arr[y]=nums[x];
            y++;
        }
        for(int x=0;x<i;x++)
        {
            arr[y]=nums[x];
            y++;
        }
        
        for(int x=0;x<nums.size();x++)
        {
            nums[x]=arr[x];
        }
    }
};