class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashh;
        vector<int> ans;
        int lock=0;
        for(int i=0;i<nums.size();i++){
            lock=target-nums[i];
            if(hashh.find(lock)!=hashh.end()){
                ans.push_back(i);
                ans.push_back(hashh[lock]);
                break;
            }
            hashh[nums[i]]=i;
        }
        return ans;
    }
};