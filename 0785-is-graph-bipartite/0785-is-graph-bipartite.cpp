class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color){
        for(auto neighbor : graph[node]){
            if(color[neighbor]==-1){
                color[neighbor]=1-color[node];
                if(dfs(neighbor,graph,color)==false) return false;
            }else if(color[neighbor]==color[node]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int m=graph.size();
        vector<int> color(m,-1);
        for(int i=0;i<m;i++){
            if(color[i]==-1){
                color[i]=0;
                if(dfs(i,graph,color)==false) return false;
            }
        }
        return true;
    }
};