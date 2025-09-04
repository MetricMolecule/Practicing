class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int maxlen=0;
        int cnt=0;
        vector<int> lett(26,0);
        for(int right=0;right<s.size();right++){
            lett[s[right]-'A']++;
            cnt= max(cnt,lett[s[right]-'A']);
            while((right-left+1)-cnt>k){
                lett[s[left] - 'A']--;
                left++;
            }maxlen=max(maxlen,right-left+1);
        }return maxlen;
    }
};