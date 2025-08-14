class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(), nums.end());
        while(low<high){
            int mid= (low+high)/2;
            int check=0;
            for(int i=0;i<nums.size();i++){
                check+=(nums[i] + mid - 1) / mid;
            }if(check>threshold){low=mid+1;}
            else{high=mid;}
        }return low;
    }
};