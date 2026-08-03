class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);

        int l = 0, r = 0, maxC = 0;
        int res = 1;

        while (l <= r && r < s.size()) {
            count[s[r] - 'A']++;
            maxC = max(maxC, count[s[r] - 'A']);

            if ((r - l + 1) - maxC > k) {
                count[s[l] - 'A']--;
                l++;
            }

            res = max(res, r - l + 1);
            r++;
        }

        return res;
    }
};
