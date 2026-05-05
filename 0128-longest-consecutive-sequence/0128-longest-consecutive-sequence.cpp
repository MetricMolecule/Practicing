class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int check=0;
        int longest=0;
        unordered_set<int> st(nums.begin(),nums.end());
        for(int n : st){
            if(st.find(n-1)==st.end()){
                int curr= n;                
                int len=1;
                while(st.find(curr+1)!=st.end()){
                    len+=1;
                    curr+=1;
                }
                longest=max(longest,len);
            }
        }
        return longest;
    }
};