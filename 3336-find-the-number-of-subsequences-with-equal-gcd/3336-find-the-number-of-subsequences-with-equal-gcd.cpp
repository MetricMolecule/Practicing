class Solution {
public:
    const int mod=1e9+7;
    vector<vector<vector<int>>> dp;
    int solve(int index, int gcd1, int gcd2, vector<int>& nums){
        if(index==nums.size()){
            if(gcd1==gcd2 && gcd1!=0) return 1;
            return 0;
        }
        if(dp[index][gcd1][gcd2]!=-1) return dp[index][gcd1][gcd2];
        
        long long ans=0;
        ans = (ans+solve(index+1,gcd1,gcd2,nums)%mod)%mod;

        int newgcd1=0;
        if (gcd1 == 0)
            newgcd1 = nums[index];
        else
            newgcd1 = gcd(gcd1, nums[index]);

        ans = (ans+solve(index+1,newgcd1,gcd2,nums)%mod)%mod;

        int newgcd2=0;
        if (gcd2 == 0)
            newgcd2 = nums[index];
        else
            newgcd2 = gcd(gcd2, nums[index]);
            
        ans = (ans+solve(index+1,gcd1,newgcd2,nums)%mod)%mod;

        return dp[index][gcd1][gcd2]=ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        // make a dp vector having the gcd of the elements?
        // dp will be (index,gcd1,gcd2)
        // memset(dp, -1, sizeof(dp)); // dunno what memset does
        dp=vector<vector<vector<int>>>(nums.size()+1,vector<vector<int>>(201,vector<int>(201,-1)));
        return solve(0, 0, 0, nums);
    }
};