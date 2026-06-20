class Solution {
public:
    int convertTime(string current, string correct) {
        int curr= stoi(current.substr(0,2))*60 + stoi(current.substr(3,2));
        int target= stoi(correct.substr(0,2))*60 + stoi(correct.substr(3,2));
        int diff= target-curr;
        int ans=0;
        ans = ans+ diff/60;
        diff = diff%60;
        ans = ans+ diff/15;
        diff = diff%15;
        ans = ans+ diff/5;
        diff = diff%5;
        ans = ans+ diff/1;
        diff = diff%1;
        return ans;
    }
};