class Solution {
public:
    bool solve(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target==0) return true;
        if(i==0) return nums[0]==target;
        // main storing thing (memoisation)
        if(dp[i][target] != -1) return dp[i][target];
        
        bool pick=false;
        if(nums[i]<=target){
            pick = solve(i-1,target-nums[i],nums,dp);
        }
        bool notpick = solve(i-1,target,nums,dp);
        return dp[i][target] = pick || notpick;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i : nums){
            sum += i;
        }
        if(n==1) return false;
        if(sum%2!=0) return false;
        // states required - index am standing & how much target left
        int target = sum/2;
        // dp states -1 -> not computed, 0-> false, 1-> true
        vector<vector<int>> dp (n,vector<int>(target+1,-1));

        return solve(n-1,target,nums,dp);
    }
};