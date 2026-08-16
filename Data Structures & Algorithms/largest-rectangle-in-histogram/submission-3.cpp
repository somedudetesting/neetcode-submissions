class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> stk;

        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (stk.empty()) {
                res = max(heights[i], res);
                stk.push({heights[i], i});
                continue;
            }

            int idx = i;
            while (!stk.empty() && heights[i] < stk.top().first) {
                res = max(res, stk.top().first * (i - stk.top().second));
                idx = stk.top().second;
                stk.pop();
            }

            stk.push({heights[i], idx});
        }

        while (!stk.empty()) {
            res = max(res, stk.top().first * ((int)heights.size() - stk.top().second));
            stk.pop();
        }

        return res;
    }
};
