class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // nahi ata ye fuddu question, DP states bnane honge XOR ke, 1d DP
        const int maxx=2048;
        vector<bool> seen(maxx,false);
        vector<bool> triplet_xor(maxx, false);
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int pair=nums[i]^nums[j];
                seen[pair]=true;
            }
        }
        for(int x=0;x<maxx;x++){
            if(!seen[x])continue;
            for(int v:nums){
                triplet_xor[x^v]=true;
            }
        }

        int ans=0;
        for(auto s : triplet_xor){
            ans+=s;
        }
        return ans;
    }
};