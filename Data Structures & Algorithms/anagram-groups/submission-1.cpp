class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ga;

        for (const string& str : strs) {
            vector<int> count(26, 0);

            for (char c : str) {
                count[c - 'a']++;
            }

            string key = to_string(count[0]);

            for (int i = 1; i < 26; i++) {
                key += ',' + to_string(count[i]);
            }

            ga[key].push_back(str);
        }

        vector<vector<string>> res;

        for (auto group : ga) {
            res.push_back(group.second);
        }

        return res;
    }
};
