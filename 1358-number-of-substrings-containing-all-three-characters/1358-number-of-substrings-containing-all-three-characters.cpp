class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mpp;
        mpp['a']=0;
        mpp['b']=0;
        mpp['c']=0;
        int ans=0;
        int i=0;
        int j=0;
        while(j<s.size()){
            mpp[s[j]]++;
            while(mpp['a']>=1 && mpp['b']>=1 && mpp['c']>=1){
                ans+=s.size()-j;
                mpp[s[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};