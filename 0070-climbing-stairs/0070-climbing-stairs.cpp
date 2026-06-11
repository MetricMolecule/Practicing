class Solution {
public:
    int climbStairs(int n) {
        // it is simple checking of how many steps it took to reach the element before and the element before that
        // because we can jump from one place before or two places befrore, options={1,2};
        if(n==1) return 1;
        if(n==2) return 2;
        vector<int> dp(n);
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n-1];
    }
};