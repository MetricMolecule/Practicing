class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // constraint is 10^5, i cant use O(n^2)
        // since it is not sorted, we need to find a connection rather than checking next one
        // we sort according to the values in nums vector
        vector<pair<int,int>> values;
        for(int i=0;i<n;i++){
            values.push_back({nums[i],i});
        }
        sort(values.begin(),values.end());
        // positions vector, original positions
        vector<int> pos(n);
        for(int i=0;i<n;i++){
            pos[values[i].second]=i;
        }
        // next position after a jump
        vector<int> nxt(n);
        int r=0;
        for(int i=0;i<n;i++){
            while(r+1<n && values[r+1].first-values[i].first<=maxDiff){
                r++;
            }
            nxt[i]=r;
        }
        // binary jumping table
        const int log=20;  // 2^20
        vector<vector<int>> jump(log,vector<int>(n));
        // we already have first jump vector
        for(int i=0;i<n;i++){
            jump[0][i]=nxt[i];
        }
        for(int i=1;i<log;i++){
            for(int j=0;j<n;j++){
                jump[i][j]=jump[i-1] [jump[i-1][j]];
            }
        }
        vector<int> ans;

        for(auto& it : queries){
            int u=pos[it[0]];
            int v=pos[it[1]];

            if(u>v) swap(u,v);
            if(u==v){
                ans.push_back(0);
                continue;
            } 
            if(nxt[u]==u){
                ans.push_back(-1);
                continue;
            } 

            int current=u;
            int steps=0;
            for(int k=log-1;k>=0;k--){
                if(jump[k][current]<v){
                    current=jump[k][current];
                    steps+=(1<<k);
                }
            }
            current=nxt[current];
            steps++;
            if(current>=v)
                ans.push_back(steps);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};