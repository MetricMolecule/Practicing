class Solution {
public:
    int rev(int x){
        int revnum=0;
        while(x!=0){
            int d=x%10;
            x=x/10;
            revnum = revnum*10+d;
        }return revnum;
    }
    int countDistinctIntegers(vector<int>& nums) {
        int cnt = 0;
        set <int> st;
        for(int i=0;i<nums.size();i++){
            int pix=0;
            st.insert(nums[i]);
            pix=rev(nums[i]);
            st.insert(pix);
        } return st.size();
    }
};