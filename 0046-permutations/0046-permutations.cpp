class Solution {
public:
    void swap(vector<int>& arr, int i, int j){
        int tmp=arr[i];
        arr[i]=arr[j];
        arr[j]=tmp;
    }
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int i){
        int n=nums.size();
        if(i==n){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<n;j++){
            swap(nums,i,j);
            solve(nums,i+1);
            swap(nums,i,j);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        solve(nums, 0);
        return ans;
    }
};