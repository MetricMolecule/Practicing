class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //frequency storing hashmap
        unordered_map<int, int> freq;
        for(int i :nums){
            freq[i]++;
        }
        //max heap to store with respect to frquencies as a pair, frequency first one of pair
        priority_queue<pair<int,int>> pq;
        for(auto it : freq){
            pq.push({it.second,it.first});
        }
        vector<int> ans;
        for(int i=0 ; i<k ; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};