class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq; //max heap to store and change on it
        //initial store in priority queue;
        for(int i:stones){
            pq.push(i);
        }
        while(pq.size()>1){
            int l1=pq.top();
            pq.pop();
            int l2=abs(pq.top()-l1);
            pq.pop();
            pq.push(l2);
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};