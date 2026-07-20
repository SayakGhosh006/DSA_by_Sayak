class Solution {
public:
    // int memoisation(int m,int n,vector<vector<int>> &dp){
    //  if(m==1 || n==1) return 1;
    //     if(m<=0 || n<=0) return 0;
    //     if(dp[m][n] != -1) return dp[m][n];
    //     int up=uniquePaths(m-1,n);
    //     int left=uniquePaths(m,n-1);

    //      return dp[m][n]=left+up;
    // }

    int uniquePaths(int m, int n) {
        //   vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {

            vector<int> temp(n, 0);

            for (int j = 0; j < n; j++) {
                // Base case
                if (i == 0 && j == 0) {
                    temp[j] = 1;
                    continue;
                }

            int up = 0;
            int left = 0;

            if (i > 0)
                up = prev[j];


            if (j > 0)
                left = temp[j - 1];
            temp[j] = up + left;
        }

        prev = temp;
    }

    return prev[n - 1];
}
        
        //   return memoisation(m,n,dp);
    
    
};