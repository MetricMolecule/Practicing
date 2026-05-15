class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count=0;
        int lastend=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(lastend>intervals[i][0]) {
                count++;
                lastend=min(lastend,intervals[i][1]);
            }else{
                lastend=intervals[i][1];
            }
        }
        return count;
    }
};