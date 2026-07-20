class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        //flatten the grid to 1d vector
        vector<int> flatten (m*n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                flatten[(i*n)+j]=grid[i][j];
            }
        }
        // rotate the 1d vector by k 
        vector<int> rotated(m*n,0);
        for(int i=0;i<m*n;i++){
            rotated[(i+k)%(m*n)]=flatten[i];
        }
        // form the new grid according to the rotated array
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=rotated[i*n+j];
            }
        }
        return ans;
    }
};