class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stk;

        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            if (stk.empty()) {
                stk.push({temperatures[i], i});
                continue;
            }

            while (!stk.empty() && temperatures[i] > stk.top().first) {
                int distance = i - stk.top().second;
                res[stk.top().second] = distance;
                stk.pop();
            }

            stk.push({temperatures[i], i});
        }

        return res;
    }
};
