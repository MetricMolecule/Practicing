class Solution {
public:
    // we need states in such a way that, dp[i][j] 
    // where i tells the index and j tells whether we have this stock or not
    // if we have a stock- we sell or not sell
    // if we dont have a stock- we buy or dont buy
    int solve(int i, int canbuy, vector<int>& prices, vector<vector<int>>& dp){
        if(i==prices.size()) return 0;
        if(dp[i][canbuy]!=-1) return dp[i][canbuy];
        // if we have the stock
        if(canbuy==0){
            int sell= prices[i]+ solve(i+1,1,prices,dp);
            int hold= solve(i+1,0,prices,dp);
            return dp[i][canbuy]= max(sell,hold);
        }
        // if we dont have the stock i.e. canbuy==1
        else{
            int buy= -prices[i]+solve(i+1,0,prices,dp);
            int skip= solve(i+1,1,prices,dp);
            return dp[i][canbuy]= max(buy,skip);
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // we need states for which we can see max profit till now
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};