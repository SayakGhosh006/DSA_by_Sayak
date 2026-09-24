class Solution {
public:
    int sums(int x){
    int sum=0;
     while(x>0){
        int d=x%10;
        sum += d;
        x /= 10;
     }
     return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(sums(nums[i])==i){
               return i;
            }
        }
        return -1;
    }
};