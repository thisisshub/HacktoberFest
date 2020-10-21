/**
 * Author: Siddhant Pandya
 * Problem: 74. Search a 2D Matrix
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.empty() && !matrix[0].empty())
        {
        for(int x=0;x<matrix.size();x++)
        {
            if(matrix[x][matrix[x].size()-1]>=target)
            {
                for(int y=0;y<matrix[x].size();y++)
                {
                    if(matrix[x][y]==target)
                    {
                        return true;
                    }
                }
                break;
            }
        }
        }
        
        return false;
    }
};