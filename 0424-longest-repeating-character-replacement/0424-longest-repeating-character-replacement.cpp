class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mpp;
        int n=s.length();
        int i=0;
        int j=0;
        int maxlen=1;
        int maxfreq=0;
        while(j<n){
            mpp[s[j]]++;
            maxfreq=max(maxfreq,mpp[s[j]]);
            while( (j-i+1) - maxfreq > k){
                mpp[s[i]]--;
                if(mpp[s[i]]==0){
                    mpp.erase(s[i]);
                }i++;
            }
            j++;
            maxlen=max(maxlen,j-i);
        }
        return maxlen;
    }
};