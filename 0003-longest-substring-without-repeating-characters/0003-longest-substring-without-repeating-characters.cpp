class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int left=0;
        int maxlen=0;
        for(int right=0;right<s.size();right++){
            char c= s[right];
            while(mpp.find(c)!=mpp.end() && mpp[c]>=left){
                left=mpp[c]+1;
            }mpp[c]=right;
            maxlen=max(maxlen,right-left+1);
        }return maxlen;

    }
};