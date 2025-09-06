class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int ans=0;
        int sum=0;
        for(int i:nums){
            sum+=(i%2);
            if(mpp.find(sum-k)!=mpp.end()){
                ans+=mpp[sum-k];
            }mpp[sum]++;
        }return ans;
    }
};