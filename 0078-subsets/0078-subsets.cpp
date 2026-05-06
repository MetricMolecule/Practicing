class Solution {
public:
    vector<vector<int>> ans; //global vector to store answer after recurstion
    void solve(vector<int>& nums,vector<int> temp, int i){
        int n=nums.size();
        if(i==n){
            ans.push_back(temp);  //copying temp vector in ans vector, temp vector reused each time
            return;    // ending condition of recursion fucntion(0-->size of array)
        }
        solve(nums,temp,i+1); 
        temp.push_back(nums[i]); 
        solve(nums,temp,i+1);
        temp.pop_back(); //backtracking, removing
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(nums,temp,0);
        return ans;
    }    
};