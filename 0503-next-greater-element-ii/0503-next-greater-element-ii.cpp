class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> nge(n);
        stack<int> st;
        for(int i=2*n-1;i>=0;i--){
            int ix=i%n;
            while(!st.empty() && st.top()<=nums[ix]){
                st.pop();
            }if(st.empty()){nge[ix]=-1;}
            else{nge[ix]=st.top();}
            st.push(nums[ix]);
        }return nge;
    }
};