/**
 * Author: Siddhant Pandya
 * Problem: 11. Container With Most Water
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0;
        int l=0, r=height.size()-1;
        while(l<r)
        {
            int temph=min(height[l],height[r]);
            if(area<(temph*(r-l)))
            {
                area=temph*(r-l);
            }
            
            if(height[l]<height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return area;
    }
};