class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=0;
        for(int x=i;x<=j;x++){
            int left=solve(i,x-1,nums,dp);
            int right=solve(x+1,j,nums,dp);
            int cost=left+right+nums[x]*nums[i-1]*nums[j+1];
            maxi=max(maxi,cost);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return solve(1,n,nums,dp);
    }
};