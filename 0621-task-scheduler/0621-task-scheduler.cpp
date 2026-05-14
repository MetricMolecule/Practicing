class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        for(char c : tasks){
            freq[c]++;
        }
        pair<int,char> p;
        priority_queue<pair<int,char>> pq;
        for(auto it: freq){
            p={it.second,it.first};
            pq.push(p);
        }
        int count=0;
        while(!pq.empty()){
            vector<pair<int,char>> temp;
            int task=0;
            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
                    auto x= pq.top();
                    pq.pop();
                    x.first--;
                    task++;
                    if(x.first>0) temp.push_back(x);
                }
            }
            for(auto it : temp){
                pq.push(it);
            }
            if(pq.empty()) count+=task;
            else count+=n+1;
        }
        return count;
    }
};