class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int r, int c,int& area){
        int m=grid.size();
        int n=grid[0].size();
        if(r<0 || c<0 || r>m-1 || c>n-1) return;
        if(grid[r][c]==0 || visited[r][c]!=0) return;
        visited[r][c]=1;
        area++;
        dfs(grid,visited,r-1,c,area);
        dfs(grid,visited,r,c-1,area);
        dfs(grid,visited,r+1,c,area);
        dfs(grid,visited,r,c+1,area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int area=0;
                if(grid[i][j]==1){
                    dfs(grid,visited,i,j,area);
                }
                maxarea=max(maxarea,area);
            }
        }
        return maxarea;
    }
};