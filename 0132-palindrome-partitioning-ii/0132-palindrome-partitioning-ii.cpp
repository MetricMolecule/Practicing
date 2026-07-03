class Solution {
public:
    int solve(int i, string& s, vector<int>& dp, vector<vector<bool>>& pal){
        if(i==s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int mini=INT_MAX;
        // dp[i] tells from s[i.....n-1] has how many palindromes
        for(int x=i;x<s.size();x++){
            if(pal[i][x]==true){    
                int cost=1+solve(x+1,s,dp,pal);
                mini=min(mini,cost);
            }
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        int n=s.size();
        if(n==1) return 0;
        vector<int> dp(n,-1);

        // making the pal matrix which will have info whether s[i....j] is palindrome or not
        vector<vector<bool>> pal(n, vector<bool>(n,false));
        // we start i from the end and j from there to the end
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j]){
                    if(j-i<=1){
                        pal[i][j]=true;
                    }else pal[i][j]=pal[i+1][j-1];
                }
            }
        }
        return solve(0,s,dp,pal)-1;
    }
};