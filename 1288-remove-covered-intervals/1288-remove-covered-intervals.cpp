class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // we need to have first one increasing order and the second element in decreasing order
        sort(intervals.begin(),intervals.end(),
        [](vector<int>& a, vector<int>& b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }else{
                return a[0]<b[0];
            }
        });
        int n = intervals.size();
        int i=0;
        int j=1;
        int count=n;
        while(i<n-1 && j<n){
            int a=intervals[j][0];
            int b=intervals[j][1];
            int c=intervals[i][0];
            int d=intervals[i][1];
            if(c<=a && b<=d){
                j++;
                count--;
            }else{
                i=j;
                j++;
            }
        }
        return count;
    }
};