class Solution {
public:
    int m, n;
    int left = 0;
    int up = 1;
    int MOD = 1e9 + 7;

    int solve(vector<vector<int>>& grid, int i, int j,
              int camefrom,
              vector<vector<array<int, 2>>>& t) {

        if (i >= m || j >= n)
            return 0;

        if (i == m - 1 && j == n - 1)
            return 1;

        if (t[i][j][camefrom] != -1)
            return t[i][j][camefrom];

        int totalPathsCount = 0;

        if (grid[i][j] == 1) {

            if (camefrom == left) {
                totalPathsCount = solve(grid, i + 1, j, up, t);
            }
            else {
                totalPathsCount = solve(grid, i, j + 1, left, t);
            }

        }
        else {

            totalPathsCount = (
                solve(grid, i, j + 1, left, t) +
                solve(grid, i + 1, j, up, t)
            ) % MOD;

        }

        return t[i][j][camefrom] = totalPathsCount;
    }

    int uniquePaths(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        vector<vector<array<int, 2>>> t(
            m, vector<array<int, 2>>(n, {-1, -1})
        );

        return solve(grid, 0, 0, left, t);
    }
};