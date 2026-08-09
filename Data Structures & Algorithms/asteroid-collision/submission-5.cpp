class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        bool t = false;
        deque<int> res;
        for (int val : asteroids) {
            while (!stk.empty() && val < 0 && stk.top() > 0) {
                int diff = val + stk.top();
                if (diff < 0) {
                    stk.pop();
                    continue;
                } else if (diff > 0) {
                    val = 0;
                    break;
                } else {
                    stk.pop();
                    val = 0;
                    break;
                }
            }
            if (val != 0) {
                stk.push(val);
            }
        }

        while (!stk.empty()) {
            res.push_front(stk.top());
            stk.pop();
        }

        return vector<int>(res.begin(), res.end());
    }
};