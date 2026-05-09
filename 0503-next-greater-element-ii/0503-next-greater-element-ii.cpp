class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i = 2*n-1;i>=0;i--){
            int ix=i%(nums.size());
            while(!st.empty() && st.top()<=nums[ix]){
                st.pop();
            }
            if(i<n){
                if(!st.empty()) ans[ix]=st.top();
            }
            st.push(nums[ix]);
        }
        return ans;
    }
};