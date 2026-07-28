class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        string half = s.substr(0, n / 2);
        sort(half.begin(), half.end());

        string ans = half;

        // Add middle character if length is odd
        if (n % 2 == 1) {
            ans += s[n / 2];
        }

        // Add reverse of first half
        string rev = half;
        reverse(rev.begin(), rev.end());
        ans += rev;

        return ans;
    }
};