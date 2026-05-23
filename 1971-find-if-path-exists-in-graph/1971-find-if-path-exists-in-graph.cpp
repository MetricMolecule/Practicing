class Solution {
public:
    bool dfs(int node, int destination, vector<vector<int>>& adj, vector<int>& visited){
        // base case- if neighbor node can reach destination, return true
        if(node==destination){
            return true;
        }
        // update visted array all the time for no revisits
        visited[node]=1;
        // iterate in the adjacent graph matrix we made
        for(auto neighbor : adj[node]){
            if(visited[neighbor]==0){  
                if(dfs(neighbor,destination,adj,visited)){
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n,0);
        return dfs(source, destination, adj, visited);

    }
};