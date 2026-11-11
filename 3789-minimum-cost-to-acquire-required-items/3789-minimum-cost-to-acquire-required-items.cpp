class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(cost1+cost2<costBoth)
            return (1LL*cost1*need1) + (1ll*cost2*need2);
        int mn=min(need1,need2);
        long long totalCost= 1LL* costBoth*mn;
        need1 -= mn;
        need2 -= mn;
        if(need1>0){
           totalCost += 1LL*need1*min(costBoth,cost1);
        }else if(need2>0){
           totalCost += 1LL*need2*min(costBoth,cost2);
        }
        return totalCost;
    }
};