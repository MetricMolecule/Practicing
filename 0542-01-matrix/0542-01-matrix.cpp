class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,-1)); //default value taken -1, we put it zero when we see zero, and add after we get distance from zero for 1, basically if visited, it is not -1.
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            int x= p.first;
            int y= p.second;
            if(x>0 && ans[x-1][y]==-1){
                ans[x-1][y]=ans[x][y]+1;
                q.push({x-1,y});
            }
            if(x<m-1 && ans[x+1][y]==-1){
                ans[x+1][y]=ans[x][y]+1;
                q.push({x+1,y});
            }
            if(y>0 && ans[x][y-1]==-1){
                ans[x][y-1]=ans[x][y]+1;
                q.push({x,y-1});
            }
            if(y<n-1 && ans[x][y+1]==-1){
                ans[x][y+1]=ans[x][y]+1;
                q.push({x,y+1});
            }
        }
        return ans;
    }
};