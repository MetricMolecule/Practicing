class Solution {
public:
    int count=0;
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited,int r, int c){
        int m=grid.size();
        int n=grid[0].size();
        if(r<0 || c<0 || r>m-1 || c>n-1) return;
        if(visited[r][c] || grid[r][c]=='0') return;
        
        visited[r][c]=1;        
        dfs(grid,visited,r-1,c);
        dfs(grid,visited,r,c-1);
        dfs(grid,visited,r+1,c);
        dfs(grid,visited,r,c+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && visited[i][j]==0) {
                    count++;
                    dfs(grid,visited,i, j);
                }
            }
        }
        return count;
    }
};