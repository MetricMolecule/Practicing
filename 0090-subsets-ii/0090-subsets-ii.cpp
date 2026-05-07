class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, vector<int>& temp, int i){
        int n=nums.size();
        if(i==n){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<n;j++){
            if(j>i && nums[j]==nums[j-1]){
                continue;
            }
            temp.push_back(nums[j]);
            solve(nums,temp,j+1);
            temp.pop_back();
        }ans.push_back(temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        solve(nums,temp,0);
        return ans;
    }
};