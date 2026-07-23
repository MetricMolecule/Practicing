class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        if(n==2) return 2;
        int power=1;
        while(power<=n){
            power = power<<1;
        }
        return power;
    }
};