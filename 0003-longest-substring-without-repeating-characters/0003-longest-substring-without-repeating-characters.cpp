class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans=0;
        unordered_map<char,int> freq;
        int i=0;
        int j=0;
        while(j<n){
            while(freq.find(s[j])!=freq.end()){
                freq[s[i]]--;
                if(freq[s[i]]==0){
                    freq.erase(s[i]);
                }
                i++;
            }
            freq[s[j]]++;
            j++;
            ans=max(ans,j-i);
        }
        return ans;
    }
};