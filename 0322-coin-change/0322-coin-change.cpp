class Solution {
public:
    int solve(int i, int target, vector<int>& coins, vector<vector<int>>& dp){
        if(i==0){
            if(target%coins[i]==0) return target/coins[0];
            else return 1e9;
        }
        
        if(dp[i][target]!=-1) return dp[i][target];
        // make pick as maximum, because we are returning min(pick,notpick);
        int pick=1e9;
        if(coins[i]<=target){
            pick=1+solve(i,target-coins[i],coins,dp);
        }
        int notpick=solve(i-1,target,coins, dp);
        return dp[i][target]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int n=coins.size();

        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = solve(n-1,amount,coins,dp);
        if(ans>=1e9) return -1;
        else return ans;
    }
};