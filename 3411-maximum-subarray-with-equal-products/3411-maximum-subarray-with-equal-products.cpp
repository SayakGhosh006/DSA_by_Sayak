class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            long long product = 1;

            for (int j = i; j < n; j++) {

                if (product > LLONG_MAX / nums[j])
                    break;

                product *= nums[j];

                long long g = 0;
                long long l = 1;

                for (int k = i; k <= j; k++) {
                    g = gcd(g, (long long)nums[k]);
                    l = l / gcd(l, (long long)nums[k]) * nums[k];
                }

                if (product == g * l)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};