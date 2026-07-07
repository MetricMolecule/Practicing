class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // approach- use priority queue(min heap) to get answers in distance order
        // pair- 1st value, is distance & second value is index of the point in points 2D vector
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>> > pq;
        int n=points.size();
        for(int i=0;i<n;i++){
            int u=points[i][0];
            int v=points[i][1];
            int dis = (u*u) + (v*v);
            pq.push({dis,i});
        }
        vector<vector<int>> ans;

        for(int i=0;i<k;i++){
            vector<int> temp;
            auto p = pq.top();
            pq.pop();
            int index=p.second;
            temp=points[index];
            ans.push_back(temp);
        }
        return ans;

    }
};