class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> freq;
        for(char c : text){
            freq[c]++;
        }
        int count=0;
        count=min({freq['b'], freq['a'], freq['l']/2, freq['o']/2, freq['n']});
        return count;
    }
};