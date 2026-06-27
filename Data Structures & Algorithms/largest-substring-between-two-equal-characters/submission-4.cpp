class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> prevChar;

        int res = -1;
        for (int i = 0; i < s.length(); i++) {
            if (prevChar.find(s[i]) != prevChar.end()) {
                res = max(res, i - prevChar[s[i]] - 1);
            } else {
                prevChar[s[i]] = i;
            }
        }

        return res;
    }
};