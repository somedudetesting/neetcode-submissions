class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        unordered_map<char, char> pairs = {
            {']', '['},
            {')', '('},
            {'}', '{'},
        };
        for (char ch : s) {
            if (ch == ']' || ch == '}' || ch == ')') {
                if (stk.empty()) return false;
                if (pairs[ch] == stk.top()) {
                    cout << stk.top() << " " << pairs[ch] << endl;
                    stk.pop();
                } else {
                    return false;
                }
            } else {
                stk.push(ch);
            }
        }

        if (stk.empty()) return true;
        else return false;
    }
};
