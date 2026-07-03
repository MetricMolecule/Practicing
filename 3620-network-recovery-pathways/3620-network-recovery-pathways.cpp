class Solution {
public:
    bool check(int limit, vector<vector<pair<int,int>>>& graph, vector<int>& topo, vector<bool>& online, long long k){
        int n=online.size();
        long long inf=1e18;
        vector<long long> dp(n,inf);
        dp[0]=0;
        for(int i=0;i<n;i++){
            int u=topo[i];
            if(dp[u]==inf){
                continue;
            }
            if(u!=0 && u!=n-1 && online[u]==false){
                continue;
            }
            for(int x=0;x<graph[u].size();x++){
                int v=graph[u][x].first;
                int w=graph[u][x].second;
                if(w<limit) continue;
                if(v!=n-1 && online[v]==false) continue;

                dp[v]=min(dp[v],dp[u]+ (long long)w);
            }
        }
        return dp[n-1]<=k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        // this is not a dijkstra problem
        // we are given that it is DAG, so we simply use topo sort
        int n=online.size();
        // first we build the graph
        vector<vector<pair<int,int>>> graph(n);
        vector<int> incoming(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            graph[u].push_back({v,w});
            incoming[v]++;
        }
        // topo sort
        vector<int> topo;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(incoming[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(int i=0;i<graph[node].size();i++){
                int next=graph[node][i].first;
                incoming[next]--;
                if(incoming[next]==0){
                    q.push(next);
                }
            }
        }
        // ninary search
        int low=0;
        int high=1000000000;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid, graph, topo, online, k)==true){
                ans=mid;
                low=mid+1;
            }else high=mid-1;
        }
        return ans;
    }
};