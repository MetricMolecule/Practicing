class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start=1;
        int id=0;
        while(k>0){
            if (id < arr.size() && arr[id] == start) {
                id++;
            } else {
                k--;
                if (k == 0) break;
            }
            start++;
        }return start;
    }
};