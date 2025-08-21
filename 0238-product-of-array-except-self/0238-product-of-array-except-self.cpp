class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pro=1;
        int zeros=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0)
                pro *= nums[i];
            else
                zeros++;
        }vector<int> ans(nums.size(),0);
        for(int i = 0; i < nums.size(); i++) {
        if(zeros > 1) {
            ans[i] = 0;
        } else if(zeros == 1) {
            if(nums[i] == 0) {
                ans[i] = pro;
            } else {
                ans[i] = 0;
        }
        } else {
            ans[i] = pro / nums[i];
        }
    }return ans;
    }
};