class Solution {
public:

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // parent vector, tells which parent[i] tells it is connected to which node
        // obviously we have implemented the condition for connecting in the loop after that
        vector<int> parent(n);
        int idx=0;
        parent[0]=idx;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff){
                idx++;
            }
            parent[i]=idx;
        }
        
        vector<bool> ans;
        int len=queries.size();

        for(int i=0;i<len;i++){
            int u=queries[i][0];
            int v=queries[i][1];
            ans.push_back(parent[u]==parent[v]);
        }
        return ans;
    }
};