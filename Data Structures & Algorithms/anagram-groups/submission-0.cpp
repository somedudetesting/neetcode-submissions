class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ga;

        for (string str : strs) {
            string sorted = str;
            sort(sorted.begin(), sorted.end());

            ga[sorted].push_back(str);
        }

        vector<vector<string>> res;

        for (auto group : ga) {
            res.push_back(group.second);
        }

        return res;
    }
};
