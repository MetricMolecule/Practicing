class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // lol, just need to see the minimum of all the weights, as we can always travel back and reach the final one, shit question
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        vector<int> visited(n+1,0);
        queue<int> q;
        q.push(1);
        visited[1]=1;
        int ans=INT_MAX;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:graph[node]){
                int next=it.first;
                int weight=it.second;
                ans=min(ans,weight);
                if(visited[next]==0){
                    visited[next]=1;
                    q.push(next);
                }
            }
        }
        return ans;
    }
};