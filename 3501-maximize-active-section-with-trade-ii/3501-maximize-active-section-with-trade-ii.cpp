class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        // its a segment tree,fuck this question
        int n = s.size();

        // Count total ones
        int ones = 0;
        for (char c : s) {
            if (c == '1')
                ones++;
        }

        // Store start and end index of every zero segment
        vector<int> startZero;
        vector<int> endZero;

        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0')
                    j++;
                startZero.push_back(i);
                endZero.push_back(j - 1);
                i = j;
            } else {
                i++;
            }
        }
        int blocks = startZero.size();

        // Gain for every valley
        vector<int> gainArray;
        for (int i = 0; i < blocks - 1; i++) {
            int leftLength = endZero[i] - startZero[i] + 1;
            int rightLength = endZero[i + 1] - startZero[i + 1] + 1;
            gainArray.push_back(leftLength + rightLength);
        }

        // Sparse Table
        int m = gainArray.size();
        vector<vector<int>> sparse;
        sparse.push_back(gainArray);
        int len = 1;

        while (len * 2 <= m) {
            vector<int> current;
            for (int i = 0; i + len < sparse.back().size(); i++) {
                current.push_back(max(sparse.back()[i],
                                    sparse.back()[i + len]));
            }
            sparse.push_back(current);
            len *= 2;
        }
        // RMQ function
        auto queryMax = [&](int left, int right) {
            int length = right - left + 1;
            int k = 0;
            while ((1 << (k + 1)) <= length)
                k++;
            return max(sparse[k][left],
                    sparse[k][right - (1 << k) + 1]);
        };

        // Boundary clipped gain
        auto clippedGain = [&](int id, int l, int r) {
            int ans = gainArray[id];
            if (l > startZero[id])
                ans -= (l - startZero[id]);
            if (endZero[id + 1] > r)
                ans -= (endZero[id + 1] - r);
            return ans;
        };

        // Solve one query
        auto solve = [&](int l, int r) {
            if (blocks < 2)
                return 0;
            int leftValley =
                lower_bound(endZero.begin(), endZero.end(), l) - endZero.begin();
            int rightValley =
                upper_bound(startZero.begin(), startZero.end(), r) - startZero.begin() - 2;
            if (leftValley > rightValley)
                return 0;
            int best = 0;
            best = max(best, clippedGain(leftValley, l, r));
            best = max(best, clippedGain(rightValley, l, r));
            if (rightValley - leftValley >= 2) {
                best = max(best,
                        queryMax(leftValley + 1,
                                    rightValley - 1));
            }
            return best;
        };
        vector<int> ans;
        for (auto q : queries) {
            ans.push_back(ones + solve(q[0], q[1]));
        }
        return ans;
    }
};