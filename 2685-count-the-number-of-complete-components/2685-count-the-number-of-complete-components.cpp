class Solution {
public:
    int find(int i,vector<int>& parent){
        if(parent[i]==i) return i;
        else return parent[i]=find(parent[i],parent);
    }
    void onion(int u, int v, vector<int>& parent){
        int x=find(u,parent);
        int y=find(v,parent);
        if(y!=x){
            parent[y]=x;
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // we will use union find approach to get connected components, then check up edges and vertices (from the hint given and formula)
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            onion(u,v,parent);
        }

        unordered_map<int,int> vertices;
        for(int i=0;i<n;i++){
            int root=find(i,parent);
            vertices[root]++;
        }

        unordered_map<int,int> edgescount;
        for(auto it:edges){
            int root=find(it[0],parent);
            edgescount[root]++;
        }

        int ans=0;
        for(auto it:vertices){
            int root=it.first;
            int vertex=it.second;
            int edge=edgescount[root];
            int need= vertex*(vertex-1)/2;
            if(edge==need) ans++;
        }
        return ans;

    }
};