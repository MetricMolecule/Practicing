class Solution {
public:
    int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        // if we found same character, we do nothing
        if(s1[i]==s2[j]) return dp[i][j]=solve(i-1,j-1,s1,s2,dp);
        // if not same, we got three options - insertion, deletion, replacement
        else{
            return dp[i][j]= 1+ min({
                solve(i-1,j,s1,s2,dp), // deletion
                solve(i,j-1,s1,s2,dp), // insertion
                solve(i-1,j-1,s1,s2,dp), // replacement
            });
        }
        return 0;
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        if(word1==word2) return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,word1,word2,dp);
    }
};