class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        // we will make 2 cases
        // first where we will have first index and not last index
        // second case where we will have last index but not first index
        int len1=n-1;
        vector<int> dp_1(len1);
        if(len1==1) dp_1[0]=nums[0];
        else{
            dp_1[0]=nums[0];
            dp_1[1]=nums[1];
            if(len1>=3){
                dp_1[2]=nums[0]+nums[2];
                for(int i=3;i<len1;i++){
                    dp_1[i]=nums[i]+ max(dp_1[i-2],dp_1[i-3]);
                }
            }
        }
        int ans1=0;
        if(len1==1) ans1=dp_1[0];
        else if(len1==2) ans1=max(dp_1[0],dp_1[1]);
        else ans1= max(dp_1[len1-1],dp_1[len1-2]);
        
        // case 2
        int len2=n-1;
        vector<int> dp_2(len2);
        if(len2==1) dp_2[0]=nums[1];
        else{
            dp_2[0]=nums[0+1];
            dp_2[1]=nums[1+1];
            if(len2>=3){
                dp_2[2]=nums[1]+nums[3];
                for(int i=3;i<len2;i++){
                    dp_2[i]=nums[i+1]+max(dp_2[i-2],dp_2[i-3]);
                }
            }
        }
        int ans2 = 0;
        if(len1==1)ans2=dp_2[0];
        else if(len2==2) ans2=max(dp_2[0],dp_2[1]);
        else ans2=max(dp_2[len2-1],dp_2[len2-2]);
        return max(ans1,ans2);
    }
};