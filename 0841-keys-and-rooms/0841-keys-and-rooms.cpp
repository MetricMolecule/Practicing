class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n,0);
        queue<vector<int>> q;
        q.push(rooms[0]);
        visited[0]=1;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int x= p.size();
            for(int i=0;i<x;i++){
                int j= p[i];
                if(visited[j]==0){
                    visited[j]=1;
                    q.push(rooms[j]);
                }
            }
        }
        for(int i : visited){
            if(i==0) return false;
        }
        return true;
    }
};