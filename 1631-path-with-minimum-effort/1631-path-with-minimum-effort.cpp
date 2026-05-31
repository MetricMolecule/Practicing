class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        >pq;
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();

            int effort=p.first;
            int row=p.second.first;
            int col=p.second.second;
            if(effort>dist[row][col]) continue;
            if(row>0){
                int neweffort=max(effort,abs(heights[row][col]-heights[row-1][col]));
                if(neweffort<dist[row-1][col]){
                    dist[row-1][col]=neweffort;
                    pq.push({neweffort,{row-1,col}});
                }
            }
            if(row<m-1){
                int neweffort=max(effort,abs(heights[row][col]-heights[row+1][col]));
                if(neweffort<dist[row+1][col]){
                    dist[row+1][col]=neweffort;
                    pq.push({neweffort,{row+1,col}});
                }
            }
            if(col>0){
                int neweffort=max(effort,abs(heights[row][col]-heights[row][col-1]));
                if(neweffort<dist[row][col-1]){
                    dist[row][col-1]=neweffort;
                    pq.push({neweffort,{row,col-1}});
                }
            }
            if(col<n-1){
                int neweffort=max(effort,abs(heights[row][col]-heights[row][col+1]));
                if(neweffort<dist[row][col+1]){
                    dist[row][col+1]=neweffort;
                    pq.push({neweffort,{row,col+1}});
                }
            }
        }
        return dist[m-1][n-1];
    }
};