class Solution {
public:
    // we have a canreach helper function
    // it tells us if for a given value, we have a valid path or not
    bool canreach(vector<vector<int>>& dist, int mid){
        int n=dist.size();
        // if the distance of starting point is less than given value, we return false already
        if(dist[0][0]<mid) return false;
        // we do BFS
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> visited(n, vector<int>(n,0));
        visited[0][0]=1;
        // direction vector
        vector<int> dx={-1,1,0,0};
        vector<int> dy={0,0,1,-1};
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
            if(x==n-1 && y==n-1){
                return true;
            }for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<n && visited[nx][ny]!=1 && dist[nx][ny]>=mid){
                    visited[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        // dictance matrix which stored minimum distance of a block from a thief block
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        // making the distance matrix
        // and multi source BFS
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                } 
            }
        }
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,1,-1};
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<n && dist[nx][ny]==INT_MAX){
                    dist[nx][ny]=1+dist[x][y];
                    q.push({nx,ny});
                }
            }
        }
        
        int high=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                high=max(high,dist[i][j]);
            }
        }

        int low=0;
        int ans=0;
        // applying binary search from highest distance to lowest distance
        // pattern is that for more safety vector, we will get false easily and for least opposite is true
        while(low<=high){
            int mid= low+(high-low)/2;

            if(canreach(dist,mid)==true){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};