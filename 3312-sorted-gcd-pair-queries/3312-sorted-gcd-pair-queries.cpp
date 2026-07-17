class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        // will take too long if computed gcd for all
        // so we will do the counted method
        int MAX = *max_element(nums.begin(), nums.end());
        int n=nums.size();
        // freqency of elements
        map<int, int> freq;
        for(int i : nums){
            freq[i]++;
        }
        // numbers divisible by 1
        vector<long long> divisible(MAX + 1, 0);
        for (int i = 1; i <= MAX; i++) {
            for (int j = i; j <= MAX; j += i)
                divisible[i] += freq[j];
        }
        //number of pairs having gcd = i
        vector<long long> exact(MAX + 1, 0);
        for (int g = MAX; g >= 1; g--) {
            long long cnt = divisible[g];
            exact[g] = cnt * (cnt - 1) / 2;

            for (int multiple = 2 * g; multiple <= MAX; multiple += g)
                exact[g] -= exact[multiple];
        }
        // prefix counts
        vector<long long> pref(MAX + 1, 0);

        for (int i = 1; i <= MAX; i++){
            pref[i] = pref[i - 1] + exact[i];
        }
        vector<int> ans;
        for (long long q : queries) {
            int g = lower_bound(pref.begin() + 1, pref.end(), q + 1) - pref.begin();
            ans.push_back(g);
        }
        return ans;
    }
};