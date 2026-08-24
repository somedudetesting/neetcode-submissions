class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stk;
        string cur;
        stringstream ss(path);
        while (getline(ss, cur, '/')) {
            if (cur.empty()) continue;
            if (cur == "..") {
                if (!stk.empty()) stk.pop_back();   
            } else if (!cur.empty() && cur != ".") {
                stk.push_back(cur);
            }
        }

        string res = "/";
        for (int i = 0; i < stk.size(); i++) {
            if (i > 0) res += "/";
            res += stk[i];
        }

        return res;
    }
};