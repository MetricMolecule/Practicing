class Solution {
public:
    vector<int> nge(vector<int>& nums){
        int n=nums.size();
        vector<int> ans(n,0);
        stack<int> st;  //will be storing indices
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }if(!st.empty()) {
                ans[i]=st.top()-i;
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> hotter= nge(temperatures);       
        return hotter;
    }
};