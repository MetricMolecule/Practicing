class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // the given graph matrix can be used as adjacency list
        queue<int> q;
        int n=graph.size();
        vector<int> outdegree(n);
        // making the outdegree array
        // outdegree will have which node has how many outgoing edges
        for(int i=0;i<n;i++){
            outdegree[i]=graph[i].size();
        }
        for(int i=0;i<n;i++){
            if(outdegree[i]==0) q.push(i);
        }
        // making a reverse graph to check how many nodes are connnecting to safe nodes
        vector<vector<int>> graph_rev(n);
        for(int i=0;i<n;i++){
            for(auto it : graph[i]){
                graph_rev[it].push_back(i);
            }
        }
        vector<int> ans;
        // checking from the reverse graph if there are any nodes connecting to the safe ones
        while(!q.empty()){
            int p=q.front();
            q.pop();
            ans.push_back(p);
            for(auto it : graph_rev[p]){
                outdegree[it]--;
                if(outdegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};