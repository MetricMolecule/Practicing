class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, vector<int>& temp, int i, int rem, int k){
        if(rem==0){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1]){continue;}
            if(nums[j]<=rem){
                temp.push_back(nums[j]);
                solve(nums,temp,j+1,rem-nums[j],k);
                temp.pop_back();
            }else break;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        solve(candidates,temp,0,target,target);
        return ans;
    }
};