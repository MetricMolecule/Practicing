class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;       // to put answer in
        int start=intervals[0][0];     // start and end variable to keep track nd make ans arrray
        int end=intervals[0][1];

        for(int i=1;i<intervals.size();i++){
            if(end>=intervals[i][0]){
                end=max(end,intervals[i][1]);    //keep the end value till we get maximum for overlap
            }else{
                ans.push_back({start,end});      //if not greater,reset it and start checking further
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        ans.push_back({start,end});           //last loop will left unchecked after comparing &adding
        return ans;
    }
};