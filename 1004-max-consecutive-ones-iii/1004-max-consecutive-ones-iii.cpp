class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int i=0;
        int j=0;
        int zeros=0;
        int maxlen=0;
        while(j<nums.size()){
            // increasing till while loop condition hits
            if(nums[j]==0) zeros++;
            //invalid window if zeros>k, increase from left till u get zeros less than k
            while(zeros>k){
                if(nums[i]==0) zeros--;
                i++;
            }
            j++; 
            maxlen=max(maxlen,j-i);
        }
        return maxlen;
    }
};