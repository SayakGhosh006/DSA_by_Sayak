class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());

        for(int x = k; ; x += k) {
            if(st.find(x) == st.end())
                return x;
        }
    }
};