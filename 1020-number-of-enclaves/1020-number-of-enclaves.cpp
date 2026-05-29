class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==1) return 0;
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || j==0 || i==m-1 || j==n-1) && grid[i][j]==1){
                    visited[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            if(i>0 && grid[i-1][j]==1 && visited[i-1][j]==0){
                visited[i-1][j]=1;
                q.push({i-1,j});
            }
            if(i<m-1 && grid[i+1][j]==1 && visited[i+1][j]==0){
                visited[i+1][j]=1;
                q.push({i+1,j});
            }
            if(j>0 && grid[i][j-1]==1 && visited[i][j-1]==0){
                visited[i][j-1]=1;
                q.push({i,j-1});
            }
            if(j<n-1 && grid[i][j+1]==1 && visited[i][j+1]==0){
                visited[i][j+1]=1;
                q.push({i,j+1});
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && visited[i][j]==0) count++;
            }
        }
        return count;
    }
};