class Solution {
public:
    int m, n;

    int delrow[4] = {-1, 0, +1, 0};
    int delcol[4] = {0, 1, 0, -1};

    long long dfs(vector<vector<int>>& grid, int r, int c) {
    //     if (r < 0 || r >= m || c < 0 || c >= n)
    //         return false;

        long long sum = grid[r][c];
            grid[r][c]=0;

        // grid[r][c] = 1; // Mark as visited

        // bool isClosed = true;

        for (int i = 0; i < 4; i++) {
            int newrow = r + delrow[i];
            int newcol = c + delcol[i];
            if (newrow >= 0 && newrow < m && newcol >= 0 && newcol < n && grid[newrow][newcol]>0)
            sum += dfs(grid,newrow,newcol);
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        long long sum = 0;
        int count=0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                   sum = dfs(grid, i, j);

                     if (sum % k == 0) {
                        count++;
                        }
                    }
            }
        }

        return count;
    }
};
