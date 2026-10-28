class Solution {
public:
    vector<vector<vector<int>>> dp;
    int m, n;

    int solve(vector<vector<int>>& grid, int r, int c, int currxor) {
        if (r >= m || c >= n) return 1e9;

        currxor ^= grid[r][c];

        if (r == m - 1 && c == n - 1)
            return currxor;

        int& ans = dp[r][c][currxor];
        if (ans != -1) return ans;

        return ans = min(solve(grid, r + 1, c, currxor),
                         solve(grid, r, c + 1, currxor));
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<int>>(
                         n, vector<int>(1024, -1)));

        return solve(grid, 0, 0, 0);
    }
};