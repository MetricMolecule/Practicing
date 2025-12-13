class Solution {
public:
    vector<int> getnse(vector<int> nums){
        int n=nums.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }if(st.empty()){nse[i]=n;}
            else{nse[i]=st.top();}
            st.push(i);
        }return nse;
    }
    vector<int> getpse(vector<int> nums){
        int n=nums.size();
        vector<int> pse(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }if(st.empty()){pse[i]=-1;}
            else{pse[i]=st.top();}
            st.push(i);
        }return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        long long n= arr.size();
        vector<int> nse = getnse(arr);
        vector<int> pse = getpse(arr);
        long long total=0;
        int mod= 1000000007;
        for(int i=0;i<n;i++){
            long long left= i-pse[i];
            long long right= nse[i]-i;
            total = (total+ (right*left % mod)* arr[i]%mod) % mod;
        }return total;
    }
};