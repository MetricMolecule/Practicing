class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low =*max_element(weights.begin(), weights.end());
        int high=0;
        for(int i : weights){
            high+= i;
        }
        while(low<high){
            int mid=(low+high)/2;
            int check=0;
            int ch=1;
            for(int i : weights){
                check+= i;
                if(check > mid){
                    ch++;
                    check=i;
                }
            }if(ch<=days){high=mid;}
            else{low=mid+1;}
        }return low;
    }
};