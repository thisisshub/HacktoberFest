class Solution {
    // support variables
    priority_queue<int, vector<int>, greater<int>> frontier;
    int *xs, *ys, len;
    void addNeighbours(int curr, vector<vector<int>>& grid) {
        // getting the curernt coordinates
        int cx = xs[curr], cy = ys[curr];
        // adding the on board neighbours if previously unmarked
        if (cx && grid[cy][cx - 1] >= 0) {
            frontier.push(grid[cy][cx - 1]);
            grid[cy][cx - 1] = -1;
        } 
        if (cy && grid[cy - 1][cx] >= 0) {
            frontier.push(grid[cy - 1][cx]);
            grid[cy - 1][cx] = -1;
        } 
        if (cx < len && grid[cy][cx + 1] >= 0) {
            frontier.push(grid[cy][cx + 1]);
            grid[cy][cx + 1] = -1;
        } 
        if (cy < len && grid[cy + 1][cx] >= 0) {
            frontier.push(grid[cy + 1][cx]);
            grid[cy + 1][cx] = -1;
        } 
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        len = grid[0].size();
        // support variables
        int res = grid[0][0], squareLen = len * len, curr, target;
        xs =  new int[squareLen], ys = new int[squareLen];
        len--;
        target = grid[len][len];
        // populating xs and ys
        for (int cy = 0; cy <= len; cy++) {
            for (int cx = 0, n; cx <= len; cx++) {
                n = grid[cy][cx], xs[n] = cx, ys[n] = cy;
            }
        }
        // marking the beginning as used and initialising the frontier
        grid[0][0] = -1;
        frontier.push(res);
        // expanding the frontier
        while (true) {
            // getting the currently new visitable node
            curr = frontier.top();
            frontier.pop();
            // updating res
            res = max(res, curr);
            // adding the current neighbours
            addNeighbours(curr, grid);
            // quitting when we reach the target
            if (frontier.top() == target) break;
        }
        return max(res, target);
    }
};
