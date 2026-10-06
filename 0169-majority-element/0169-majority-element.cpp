class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // brute-force, Time:O(n) ; Space:O(n)
        // unordered_map<int, int> freq;
        // for(int i=0;i<nums.size();i++){
        //     freq[nums[i]]++;
        // }
        // int majority=nums[0];
        // for(int i=0;i<nums.size();i++){
        //     if(freq[majority]<freq[nums[i]]){
        //         majority=nums[i];
        //     }
        // }
        // return majority;

        // boyer moore algorithm, optimised
        int candidate=-1;
        int votes=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(votes==0){
                candidate=nums[i];
                votes=1;
            } else{
                if(nums[i]==candidate) votes++;
                else votes--;
            }
        }
        return candidate;
    }
};