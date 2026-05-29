class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        if(m==1 && n==1) return;
        // doing bfs with keeping all the boundary O's and all connected to it as already visited and safe
        queue<pair<int,int>> q;
        vector<vector<int>> visited(m,vector<int>(n,0));
        // storing all the boundary O's
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || i==m-1 || j==0 || j==n-1) && board[i][j]=='O'){
                    q.push({i,j});
                    visited[i][j]=1;
                } 
            }
        }
        // doing bfs to get all the O's connected to border O's so they are safe and marked already visited
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            if(i<m-1 && board[i+1][j]=='O' && visited[i+1][j]==0){
                q.push({i+1,j});
                visited[i+1][j]=1;
            }
            if(i>0 && board[i-1][j]=='O' && visited[i-1][j]==0){
                q.push({i-1,j});
                visited[i-1][j]=1;;
            }
            if(j<n-1 && board[i][j+1]=='O' && visited[i][j+1]==0){
                q.push({i,j+1});
                visited[i][j+1]=1;;
            }
            if(j>0 && board[i][j-1]=='O' && visited[i][j-1]==0){
                q.push({i,j-1});
                visited[i][j-1]=1;;
            }
        }
        // final traversal, if we find any non visited O means it is not connected to boundary O and is hence unsafe and surrunded, so mark it X
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && visited[i][j]==0) board[i][j]='X';
            }
        }
    }
};