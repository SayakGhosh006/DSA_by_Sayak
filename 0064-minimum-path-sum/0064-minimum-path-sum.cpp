class Solution {
public:
    // int func1(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
    //    if(i==0 && j==0) return grid[0][0];
    //    if(i<0 || j<0) return 1e9;

    //    if(dp[i][j]!=-1) return dp[i][j]; 
    //    int up=grid[i][j] +func(i-1,j,grid,dp);
    //    int left=grid[i][j] +func(i,j-1,grid,dp);

    //    return dp[i][j]=min(up,left);
    // }
    int func2(int n, int m, vector<vector<int>> & grid) {
    
        // Create 1D vector for previous row
        vector<int> prev(m, 0);
    
        // Loop through each row
        for (int i = 0; i < n; i++) {
        
            // Create temp vector for current row
            vector<int> temp(m, 0);
        
            // Loop through each column
            for (int j = 0; j < m; j++) {
            
                // If at the start cell
                if (i == 0 && j == 0)
                    temp[j] = grid[i][j];
                else {
                    
                    // Take up direction if valid
                    int up = grid[i][j];
                    if (i > 0)
                        up += prev[j];
                    else
                        up += 1e9;
                    
                    // Take left direction if valid
                    int left = grid[i][j];
                    if (j > 0)
                        left += temp[j - 1];
                    else
                        left += 1e9;
                    
                    // Take minimum of both directions
                    temp[j] = min(up, left);
                }
            }
    
            // Move current row to previous
            prev = temp;
        }
    
        // Return result at destination
        return prev[m - 1];
    }
    int minPathSum(vector<vector<int>>& grid) {

        int i=grid.size();
        int j=grid[0].size();
        vector<vector<int>>dp(i,vector<int>(j,-1));
        // return func1(i-1,j-1,grid,dp);
        return func2(i,j,grid);
    }
};