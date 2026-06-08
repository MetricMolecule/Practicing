class Solution {
public:
    int find(int node, vector<int>& parent){
        if(parent[node]==node) return node;
        else return parent[node]=find(parent[node],parent);
    }
    void onion(int u, int v, vector<int>& parent){
        int x= find(u,parent);
        int y= find(v,parent);
        if(x!=y){
            parent[y]=x;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int spare=0;
        for(auto it: connections){
            int u=it[0];
            int v=it[1];
            if(find(u,parent)!=find(v,parent)){
                onion(u,v,parent);
            }else spare++;
            
        }
        set<int> leaders;
        for(int i=0;i<n;i++){
            leaders.insert(find(parent[i],parent));
        }
        int x=leaders.size();
        if(spare < x-1) return -1;
        else return x-1;
    }
};