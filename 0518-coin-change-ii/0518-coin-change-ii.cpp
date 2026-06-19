class Solution {
public:
    int solve(int i, int target, vector<int>& coins, vector<vector<int>>& dp){
        if(i==0){
            if(target%coins[i]==0) return 1;
            else return 0;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int pick=0;
        if(coins[i]<=target){
            pick=solve(i,target-coins[i],coins,dp);
        }
        int notpick=solve(i-1,target,coins, dp);
        return dp[i][target]=pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        if(amount==0) return 1;
        int n=coins.size();

        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = solve(n-1,amount,coins,dp);
        // if(ans>=1e9) return -1;
        return ans;
    }
};