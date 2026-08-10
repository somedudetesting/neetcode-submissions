class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (string& t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int n2 = stk.top(); stk.pop();
                int n1 = stk.top(); stk.pop();

                int res;

                if (t == "+") {
                    res = n1 + n2;
                } else if (t == "-") {
                    res = n1 - n2;
                } else if (t == "*") {
                    res = n1 * n2;
                } else {
                    res = n1 / n2;
                }

                stk.push(res);
            } else {
                stk.push(stoi(t));
            }
        }

        return stk.top();
    }
};
