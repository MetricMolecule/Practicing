class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums,vector<int> temp, int i){
        int n=nums.size();
        if(i==n){
            ans.push_back(temp);
            return;
        }
        solve(nums,temp,i+1);
        temp.push_back(nums[i]);
        solve(nums,temp,i+1);
        temp.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(nums,temp,0);
        return ans;
    }    
};