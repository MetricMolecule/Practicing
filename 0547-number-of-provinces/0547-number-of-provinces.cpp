class Solution {
public:
    void onion(int u, int v, vector<int>& parent){
        int x= find(u, parent);
        int y= find(v, parent);
        if(x!=y){
            parent[y]=x;
        }
    }
    int find(int node, vector<int>& parent){
        if(parent[node]==node) return node;
        else return find(parent[node],parent); 
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // solving using DSU - union and find
        int n=isConnected.size();
        // building the parent vector
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1) onion(i,j, parent);
            }
        }
        set<int> provinces;
        for(int i=0;i<n;i++){
            provinces.insert(find(parent[i],parent));
        }
        return provinces.size();
    }
};