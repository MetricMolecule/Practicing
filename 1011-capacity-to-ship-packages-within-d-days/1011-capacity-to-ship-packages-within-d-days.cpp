class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int total=0;
        int maxi=0;
        for(int w : weights){
            total+=w;
            maxi=max(maxi,w);
        }
        int low= maxi;
        int high= total;
        while(low<=high){
            int mid= low+(high-low)/2;
            int x=1;
            int check=0;
            for(int i :weights){
                check+=i;
                if(check>mid){
                    x++;
                    check=i;
                }
            }
            if(x<=days){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }return low;
    }
};