class Solution {
public:
    int find(int node, vector<int>& parent){
        if(parent[node]==node) return node;
        else return parent[node]=find(parent[node],parent);
    }
    void onion(int u, int v, vector<int>& parent){
        int x= find(u, parent);
        int y= find(v, parent);
        if(x!=y){
            parent[y]=x;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        vector<int> parent(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        stack<vector<int>> st;
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            if(find(u,parent)==find(v,parent)){
                st.push(it);
            }
            else onion(u, v, parent);
        }
        return st.top();
    }
};