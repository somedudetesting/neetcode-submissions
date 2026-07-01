class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";

        for (int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j].rfind(res + ch, 0) == 0) {
                    continue;
                }
                return res;
            }
            res += ch;
        }
        return res;
    }
};