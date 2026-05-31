class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        pq.push({0,k}); // min pq stores distance from the source and start node

        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});  //destination,weight
        }
        //BFS
        while(!pq.empty()){
            pair<int,int> p=pq.top();
            pq.pop();
            int d=p.first;
            int node=p.second;  
            if(d>dist[node]) continue;
            for(auto it: adj[node]){
                int next=it.first;
                int weight=it.second;
                if(weight+dist[node]<dist[next]){
                    dist[next]=weight+dist[node];
                    pq.push({dist[next],next});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};