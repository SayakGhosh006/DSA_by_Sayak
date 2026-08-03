class Solution {
public:
    vector<int> dp;

    int func(int i, int n, vector<int>& stoneValue) {
        if (i >= n)
            return 0;

        if (dp[i] != INT_MIN)
            return dp[i];

        int sum = 0;
        int ans = INT_MIN;

        for (int k = 0; k < 3 && i + k < n; k++) {
            sum += stoneValue[i + k];
            ans = max(ans, sum - func(i + k + 1, n, stoneValue));
        }

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        dp.assign(n, INT_MIN);

        int diff = func(0, n, stoneValue);

        if (diff > 0)
            return "Alice";
        if (diff < 0)
            return "Bob";
        return "Tie";
    }
};