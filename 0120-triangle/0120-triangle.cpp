class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if(n==1) return triangle[0][0];
        vector<vector<int>> dp = triangle;
        for(int i=1;i<n;i++){
            int x=triangle[i].size();
            for(int j=0;j<x;j++){
                if(j==0) dp[i][j] = dp[i][j]+dp[i-1][j];                // leftmost
                else if(j==i) dp[i][j] = dp[i][j] + dp[i-1][j-1];       // rightmost
                else dp[i][j]=dp[i][j]+ min(dp[i-1][j-1],dp[i-1][j]);   // middle ones
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<triangle[n-1].size();i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};