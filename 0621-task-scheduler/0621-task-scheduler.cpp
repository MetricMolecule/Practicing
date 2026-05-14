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
            // for n+1 number of times, fill distinct labels
            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
                    auto x= pq.top();  //take highest from maxheap pq
                    pq.pop();          //remove it
                    x.first--;         //decrease its frequency by 1
                    task++;            //count as executed, task increased
                    if(x.first>0) temp.push_back(x); // if frequence of task task after executing>1,
                                                     // resend it back to temp, which will add later
                                                     // to priority queue.
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