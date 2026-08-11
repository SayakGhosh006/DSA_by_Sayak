class Solution {
public:
    int missingInteger(vector<int>& nums) {
        map<int,int> mp;

        for(int x : nums){
            mp[x] = 1;
        }

        int sum = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1] + 1)
                sum += nums[i];
            else
                break;
        }

        while(mp.find(sum) != mp.end()){
            sum++;
        }

        return sum;
    }
};