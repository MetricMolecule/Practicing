class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<(long long)m*k) {return -1;}
        int low= *min_element(bloomDay.begin(),bloomDay.end());
        int high= *max_element(bloomDay.begin(),bloomDay.end());
        int ans= high;
        while(low<high){
            int mid= (low+high)/2;
            int check=0;
            int cnt=0;
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=mid){
                    cnt++;
                    if (cnt == k) {
                        check++;
                        cnt = 0;}
                }else cnt=0;
            }if (check>=m){
                ans=mid;
                high=mid;
            }else low= mid+1;
        }return ans;
    }
};