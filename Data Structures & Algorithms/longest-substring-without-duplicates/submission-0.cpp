class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> win;

        int res = 0, l = 0;
        for (int i = 0; i < s.size(); i++) {
            if (win.find(s[i]) != win.end()) {
                l = max(l, win[s[i]] + 1);
            }
            win[s[i]] = i;
            res = max(res, i - l + 1);
        }

        return res;
    }
};
