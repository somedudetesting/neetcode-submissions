class Solution {
   public:
    string encode(vector<string>& strs) {
        string res = "";
        for (string& str : strs) {
            string len = to_string(str.size());
            res += len + '#' + str;
        }
        
        return res;
    }

    vector<string> decode(string s) {
        int i = 0, n = s.size();
        vector<string> res;

        while (i < n) {
            int j = i;
            while (s[j] != '#') j++;

            int len = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + len;
            res.push_back(s.substr(i, len));
            i = j;
        }

        return res;
    }
};
