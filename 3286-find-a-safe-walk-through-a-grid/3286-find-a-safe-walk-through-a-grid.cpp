class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();
        
        if(grid[0][0]==1 & health==1) return false;
        // unsafe matrix represents unsafe[i][j] = min number of health points deduct
        vector<vector<int>> unsafe(m,vector<int>(n,INT_MAX));
        // we use dq here so that we can insert at front and back both and give priority to 0 at front
        deque<pair<int,int>> dq;
        dq.push_front({0,0});
        unsafe[0][0]=grid[0][0];

        vector<int> dx={-1,1,0,0};
        vector<int> dy={0,0,1,-1};

        while(!dq.empty()){
            auto p=dq.front();
            dq.pop_front();
            int x=p.first;
            int y=p.second;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<m && ny<n){
                    int cost=unsafe[x][y]+grid[nx][ny];
                    if(cost<unsafe[nx][ny]){
                        unsafe[nx][ny]=cost;
                        if(grid[nx][ny]==0) dq.push_front({nx,ny});
                        else dq.push_back({nx,ny});
                    }
                }
            }
        }
        return unsafe[m-1][n-1]<health;
    }
};