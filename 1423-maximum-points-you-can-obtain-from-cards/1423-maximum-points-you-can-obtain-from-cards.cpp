class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0,rsum=0,maxSum=0;
        for(int i=0;i<=k-1;i++)
            lsum += cardPoints[i];
            maxSum =lsum;
            int rIndx=cardPoints.size()-1;
            for(int j=k-1;j>=0;j--){
                lsum -= cardPoints[j];
                rsum += cardPoints[rIndx];
                rIndx--;
                maxSum=max(maxSum,lsum+rsum);
            }
        
        return maxSum;
    }
};