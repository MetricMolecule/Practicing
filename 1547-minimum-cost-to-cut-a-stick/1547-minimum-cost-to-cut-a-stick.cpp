class Solution {
public:
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;

        for(int x=i;x<=j;x++){
            int left=solve(i,x-1,cuts,dp);
            int right=solve(x+1,j,cuts,dp);
            int cost=left+right+cuts[j+1]-cuts[i-1];
            ans=min(ans,cost);
        }
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        // making the boundaries vector where we can make cuts and basically boundaries of pieces
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        int m=cuts.size();

        vector<vector<int>> dp(m,vector<int>(m,-1));
        return solve(1,m-2,cuts,dp);
    }
};