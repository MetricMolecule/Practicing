class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& ans){
        if(node==graph.size()-1){
            ans.push_back(path);
            return;
        }
        for(auto neighbor : graph[node]){
            path.push_back(neighbor);
            dfs(neighbor, graph, path, ans);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        path.push_back(0);
        dfs(0,graph,path,ans);
        return ans;
    }
};