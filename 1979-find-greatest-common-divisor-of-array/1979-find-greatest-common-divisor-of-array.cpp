class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smol=INT_MAX;
        int larj=INT_MIN;
        for(int i:nums){
            smol=min(smol,i);
            larj=max(larj,i);
        }
        return gcd(smol,larj);
    }
};