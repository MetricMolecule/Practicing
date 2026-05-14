class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        pair<int,vector<int>> p;
        priority_queue<
            pair<int,vector<int>>,
            vector<pair<int,vector<int>>>,
            greater<pair<int,vector<int>>>
            > pq;
        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y ;
            p={dist,points[i]};
            pq.push(p);
        }
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};