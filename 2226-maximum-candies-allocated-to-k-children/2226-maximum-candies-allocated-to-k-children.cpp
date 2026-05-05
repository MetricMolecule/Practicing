class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long n=candies.size();
        sort(candies.begin(),candies.end());
        long long total=0;
        for(long long c: candies){total+=c;}
        int low=1;
        long long high=candies[n-1];
        //case where it can't be distributed
        if(total<k){
            return 0;
        }
        while(low<=high){
            long long mid= low+(high-low)/2;
            long long x=0;
            for( int i=0;i<n;i++){
                x=x+ candies[i]/mid;
            }
            if(x>=k){low=mid+1;}
            else{high=mid-1;}
        }
        return high;
    }
};