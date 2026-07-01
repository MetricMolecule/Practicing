class Solution {
public:
    int solve(int i, int stock, int fee, vector<int>& prices, vector<vector<int>>& dp){
        if(i==prices.size()) return 0;
        if(dp[i][stock]!=-1) return dp[i][stock];
        if(stock==0){
            int buy = -prices[i] + solve(i+1,1,fee,prices,dp);
            int skip = solve(i+1,0,fee,prices,dp);
            return dp[i][stock]=max(buy,skip);
        }else{
            int sell = prices[i] + solve(i+1,0,fee,prices,dp)-fee;
            int hold = solve(i+1,1,fee,prices,dp);
            return dp[i][stock]=max(sell,hold);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,0,fee,prices,dp);
    }
};