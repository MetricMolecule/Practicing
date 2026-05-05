class Solution {
public:
// helper function to tell if for k number of bananas per hour, the whole stock can be completed in h hours
    bool canfinish(vector<int>& nums, int k, int h){
        int x=0;
        for(int i=0;i<nums.size();i++){
            x=x+(nums[i]+k-1)/k;
            if(x>h){
                return false;
            }
        }return x<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n= piles.size();
        sort(piles.begin(),piles.end());
        int low=1;
        int high=piles[n-1];
        int a=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canfinish(piles,mid,h)==true){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low; //taking the minimum value at which the helper function gives true value
    }
};