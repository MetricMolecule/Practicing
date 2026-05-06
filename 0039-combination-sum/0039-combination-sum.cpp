class Solution {
public:
    vector<vector<int>> ans;
    void combsum(vector<int>& nums, vector<int>& temp, int i, int rem, int k){
        if(rem==0){
            ans.push_back(temp);
            return;
        }
        if(i==nums.size()) return;
        if(nums[i]<=rem){
            temp.push_back(nums[i]);
            combsum(nums,temp,i,rem-nums[i],k);
            temp.pop_back();
        }
        combsum(nums,temp,i+1,rem,k);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        combsum(candidates,temp,0,target,target);
        return ans;
    }
};