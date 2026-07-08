class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long mod=1e9+7;
        int n=s.size();
        // preprocessing - making a positions and a digits array which tell which tell digits an =d respective indexes (non-zeros)
        vector<int> digits;
        vector<int> positions;
        for(int i=0;i<n;i++){
            if(s[i]!='0'){
                digits.push_back(s[i]-'0');
                positions.push_back(i);
            }
        }
        int m=digits.size();
        // power of 10, vector
        vector<long long> pow(m+1,1);
        for(int i=1;i<=m;i++){
            pow[i]=(pow[i-1]*10LL)%mod ;
        }
        // prefix sum vector
        vector<long long> prefix(m+1,0);
        for(int i=1;i<=m;i++){
            prefix[i]=prefix[i-1]+digits[i-1];
        }
        // prefix concatenated number vector
        vector<long long> concat(m+1,0);
        for(int i=1;i<=m;i++){
            concat[i]=(concat[i-1]*10LL + digits[i-1])%mod;
        }

        vector<int> ans;
        
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];

            int left= lower_bound(positions.begin(),positions.end(),l)-positions.begin();
            int right= upper_bound(positions.begin(),positions.end(),r)-positions.begin();
            
            if(left==right){
                ans.push_back(0);
                continue;
            } 
            int len=right-left;
            long long x= (concat[right]-concat[left]*pow[len]%mod + mod)%mod;
            long long sum=prefix[right]-prefix[left];
            ans.push_back((sum*x)%mod);
        }
        return ans;
    }
};