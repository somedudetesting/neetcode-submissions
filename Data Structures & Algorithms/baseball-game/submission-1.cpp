class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> rec;

        for (string op : operations) {
            if (op == "C") {
                rec.pop();
            } else if (op == "D") {
                int val = rec.top();
                rec.push(val+val);
            } else if (op == "+") {
                int one = rec.top();
                rec.pop();
                int two  = rec.top();
                rec.push(one);
                rec.push(one + two);
            } else {
                rec.push(stoi(op));
            }
        }

        int res = 0;
        while (rec.size() != 0) {
            res += rec.top();
            rec.pop();
        }

        return res;
    }
};