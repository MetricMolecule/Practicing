class Solution {
public: 
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int mins=0;
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                pair<int,int> p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                if(x>0 && grid[x-1][y]==1 ){
                    grid[x-1][y]=2;
                    q.push({x-1,y});
                }
                if(y>0 && grid[x][y-1]==1){
                    grid[x][y-1]=2;
                    q.push({x,y-1});
                } 
                if(x<m-1 && grid[x+1][y]==1){
                    grid[x+1][y]=2;
                    q.push({x+1,y});
                } 
                if(y<n-1 && grid[x][y+1]==1){
                    grid[x][y+1]=2;
                    q.push({x,y+1});
                }
            }
            mins++;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return mins-1;
    }
};