class Solution {
public:
    int solve(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
        // if 0 appears, we take it with plus sign and minus sign both
        if(i==0){
            if(target==0 && nums[i]==0) return 2;
            if(target==0 || nums[i]==target) return 1;
            return 0;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int pick=0;
        if(nums[i]<=target){
            pick=solve(i-1,target-nums[i],nums,dp);
        }
        int notpick=solve(i-1,target,nums,dp);
        return dp[i][target]=pick+notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i : nums){
            sum+=i;
        }
        if(sum< abs(target)) return 0;
        int positives=0;
        int negatives=0;
        // we know that, positives + negatives = sum
        // and posititves-negatives = target
        if((target+sum)%2!=0) return 0;
        positives=(target+sum)/2;
        // now the target becomes positives;
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(positives+1,-1));
        return solve(n-1,positives,nums,dp);
    }
};