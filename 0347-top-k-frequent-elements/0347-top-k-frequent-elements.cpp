class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //frequency storing hashmap
        unordered_map<int, int> freq;
        for(int i :nums){
            freq[i]++;
        }
        //min heap to store only top k frequent elements
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
        for(auto it : freq){
            pq.push({it.second,it.first});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        //put all the values as size is only k
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};