class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        
        //sort
        sort(begin(nums), end(nums));

        // low score = 0, minimise high
        return min({
            nums[n-3] - nums[0], // remove two bigger numbers
            nums[n-1] - nums[2], // remove two smaller number
            nums[n-2] - nums[1]  // remove 1 big + 1 small
        });
    }
};
