class Solution {
public:
    int m, n;

    int delRow[4] = {-1, 0, +1, 0};
    int delCol[4] = {0, 1, 0, -1};

    bool dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n)
            return false;

        if (grid[r][c] == 1)
            return true;

        grid[r][c] = 1; // Mark as visited

        bool isClosed = true;

        for (int i = 0; i < 4; i++) {
            int newRow = r + delRow[i];
            int newCol = c + delCol[i];

            bool neighborClosed = dfs(grid, newRow, newCol);
            isClosed = isClosed && neighborClosed;
        }

        return isClosed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    count += dfs(grid, i, j);
            }
        }

        return count;
    }
};