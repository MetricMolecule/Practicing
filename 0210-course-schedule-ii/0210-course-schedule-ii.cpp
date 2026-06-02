class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //building the adjacency matrix
        vector<vector<int>> adj(numCourses);
        for(auto it: prerequisites){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }
        vector<int> incoming(numCourses,0);
        for(auto neighbor : adj){
            for(auto it : neighbor){
                incoming[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(incoming[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int p=q.front();
            q.pop();
            ans.push_back(p);
            for(auto next:adj[p]){
                incoming[next]--;
                if(incoming[next]==0){
                    q.push(next);
                }
            }
        }
        if(ans.size()!=numCourses) return {};
        return ans;
    }
};