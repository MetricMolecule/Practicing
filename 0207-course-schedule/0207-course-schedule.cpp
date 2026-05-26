class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>& visited,vector<int>& pathvisited){

        visited[node]=1;
        pathvisited[node]=1;
        for(auto it : adj[node]){
            if(!visited[it]){
                if(dfs(it,adj,visited,pathvisited)){
                    return true;
                }
            }
            else if(pathvisited[it]==1) return true;
        }
        pathvisited[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(numCourses,0);
        vector<int> pathvisited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
                if(dfs(i,adj,visited,pathvisited)) return false;
            }
        }

        return true;
    }
};