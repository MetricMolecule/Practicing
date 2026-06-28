class Solution {
public:
    int bsearch(vector<int>& lis, int x){
        int low=0;
        int high=lis.size()-1;
        int ans=lis.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(lis[mid]>=x){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> lis;
        for(int i=0;i<n;i++){
            int idx=bsearch(lis,nums[i]);
            if(idx==lis.size()){
                lis.push_back(nums[i]);
            }else lis[idx]=nums[i];
        }
        return lis.size();
    }
};