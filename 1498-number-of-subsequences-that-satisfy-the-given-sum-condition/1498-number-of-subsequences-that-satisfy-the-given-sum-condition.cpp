class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int mod = 1e9 + 7;
        sort(nums.begin(),nums.end());
        int n= nums.size();
        
        //powers of 2 because up till a point if start and end value can form 2^n subsequences
        vector<int> powers(n,1);
        for(int i=1;i<n;i++){
            powers[i]=(powers[i-1]*2)%mod;
        }
        int i=0;
        int j=n-1;
        long long ans=0;
        while(i<=j){
            if(nums[i]+nums[j]<=target){
                ans=(ans+powers[j-i])%mod;
                i++;
            }else{j--;}
        }
        return ans;
    }
};