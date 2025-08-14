#include <numeric>
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int high= accumulate(nums.begin(),nums.end(),0);
        int low= *max_element(nums.begin(),nums.end());
        while(low<high){
            int mid= (low+high)/2;
            int cnt=1;
            int check=0;
            for(int i: nums){
                check+=i;
                if(check>mid){
                    cnt++;
                    check=i;
                }
            }if(cnt<=k){high=mid;}
            else{low=mid+1;}
        }return high;
    }
};