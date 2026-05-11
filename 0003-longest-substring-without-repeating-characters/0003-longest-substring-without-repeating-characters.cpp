class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int maxlen=0;
        int i=0;
        int j=0;
        unordered_map<char,int> window;
        while(j<n){
            while(window.find(s[j])!=window.end()){
                window[s[i]]--;
                if(window[s[i]]==0){
                    window.erase(s[i]);
                }
                i++;
            }
            window[s[j]]++;
            j++;
            maxlen=max(maxlen,j-i);    
        }
        return maxlen;

    }
};