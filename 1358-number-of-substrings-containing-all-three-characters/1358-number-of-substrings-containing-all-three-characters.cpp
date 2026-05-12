class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mpp;
        int i=0;
        int j=0;
        int n=s.length();
        int count=0;
        mpp['a']=0;
        mpp['b']=0;
        mpp['c']=0;

        while(j<n){
            mpp[s[j]]++;
            while(mpp['a']>=1 && mpp['b']>=1 && mpp['c']>=1){
               count += n-j; // made mistake here- at point j, every window right of it is also valid
               mpp[s[i]]--;
               i++;
            }
            j++;
        }
        return count;
    }
};