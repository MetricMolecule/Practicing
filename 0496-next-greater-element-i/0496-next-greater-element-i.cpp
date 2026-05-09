class Solution {
public:
    vector<int> nge(vector<int>& nums){
        vector<int> greater;
        stack<int> st;
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }if(st.empty()){
                greater.push_back(-1);   
            }else{
                greater.push_back(st.top());
            }
            st.push(nums[i]);
        } reverse(greater.begin(),greater.end());
        return greater;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        vector<int> ngelist=nge(nums2);
        for(int i=0;i<nums1.size();i++){
            int target=nums1[i];
            for(int j=0;j<nums2.size();j++){
                if(nums2[j]==target){ans.push_back(ngelist[j]);}
            }
        }
        return ans;
    }
};