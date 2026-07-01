class Solution {
public:
    int solve(int i, int canbuy, int maxleft, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(maxleft==0) return 0;
        if(i==prices.size()) return 0;
        if(dp[i][canbuy][maxleft]!=-1) return dp[i][canbuy][maxleft];
        if(canbuy==1){
            int buy = -prices[i]+solve(i+1,0,maxleft,prices,dp);
            int skip = solve(i+1,1,maxleft,prices,dp);
            return dp[i][canbuy][maxleft]= max(buy,skip);
        }else{
            int sell = prices[i]+solve(i+1,1,maxleft-1,prices,dp);
            int hold = solve(i+1,0,maxleft,prices,dp);
            return dp[i][canbuy][maxleft]=max(sell,hold);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        // we need 3 states of dp
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,1,k,prices,dp);
    }
};