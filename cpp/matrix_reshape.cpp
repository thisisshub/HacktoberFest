class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = size(mat), n = size(mat[0]), total = m * n;
        if(r * c != total) return mat;   
        vector<vector<int>> ans(r, vector<int>(c));
        for(int col = 0; col < n; col++) {
            for(int row = 0; row < m; row++) {
                int new_row = (n * row + col) / c;
                int new_col = (n * row + col) % c;
                ans[new_row][new_col] = mat[row][col];                
            }
        }
        return ans;
    }
};
