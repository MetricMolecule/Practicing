class Solution {
public:
    int solve(int i,int j, string& word1, string& word2, vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j] = 1+ solve(i-1,j-1,word1,word2,dp);
        }
        return dp[i][j]=max(solve(i-1,j,word1,word2,dp),solve(i,j-1,word1,word2,dp));
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int same=solve(m-1,n-1,word1,word2,dp);
        return (m+n-2*same);
    }
};