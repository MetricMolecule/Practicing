class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long total=0;
        int prev= 0;
        int freq=1;
        for(int i=0;i<nums.size();i++){
            total+= nums[i];
            while ((long long)nums[i] * (i - prev + 1) - total > k) {
            total -= nums[prev];
            prev++;
        }freq=max(freq, i-prev+1);
        }return freq;
    }
};