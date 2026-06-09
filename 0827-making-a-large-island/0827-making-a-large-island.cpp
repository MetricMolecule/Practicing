class Solution {
public:
    int find(int node, vector<int>& parent){
        if(parent[node]==node) return node;
        else return parent[node]=find(parent[node],parent);
    }
    void onion(int u, int v, vector<int>& parent, vector<int>& area){
        int x= find(u, parent);
        int y= find(v, parent);
        if(area[x]<area[y]){
            swap(x,y);
        }
        if(y!=x){
            parent[y]=x;
            area[x]+=area[y];
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        // making the parent matrix
        vector<int> parent(n*n);
        for(int i=0;i<n*n;i++){
            parent[i]=i;
        }
        // putting area=1 for all the ones in the grid
        vector<int> area(n*n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    area[i*n+j]=1;
                }
            }
        }
        // making the islands
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                int node = i*n+j;
                
                int up=(i-1)*n+j;
                int down=(i+1)*n+j;
                int left=i*n+(j-1);
                int right=i*n+(j+1);
                
                if(i>0 && grid[i-1][j]==1){
                    onion(node,up,parent,area);
                }
                if(i<n-1 && grid[i+1][j]==1){
                    onion(node,down,parent,area);
                }
                if(j>0 && grid[i][j-1]==1){
                    onion(node,left,parent,area);
                }
                if(j<n-1 && grid[i][j+1]==1){
                    onion(node,right,parent,area);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n*n;i++){
            if(parent[i]==i){
                ans=max(ans,area[i]);
            }
        }

        // trying the zero flipping (only one)
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                set<int> leaders;

                int up=(i-1)*n+j;
                int down=(i+1)*n+j;
                int left=i*n+(j-1);
                int right=i*n+(j+1);

                if(i>0 && grid[i-1][j]==1){
                    leaders.insert(find(up, parent));
                }
                if(i<n-1 && grid[i+1][j]==1){
                    leaders.insert(find(down, parent));
                }
                if(j>0 && grid[i][j-1]==1){
                    leaders.insert(find(left, parent));
                }
                if(j<n-1 && grid[i][j+1]==1){
                    leaders.insert(find(right, parent));
                }
                // solving area according to the set formed, for no redundancy
                int curr=1;
                for(auto it :leaders){
                    curr+=area[it];
                }
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};