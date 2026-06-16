class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==1) return matrix[0][0];
        vector<vector<int>> dp = matrix;
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int check=dp[i-1][j];
                if(j==0) dp[i][j] = dp[i][j] + min(dp[i-1][j],dp[i-1][j+1]);
                else if(j==n-1) dp[i][j] = dp[i][j] + min(dp[i-1][j],dp[i-1][j-1]);               
                else{
                    check=min(check,dp[i-1][j-1]);
                    dp[i][j] = dp[i][j] + min(check,dp[i-1][j+1]);
                }
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};