class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best = 0;
        int mini = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            mini = min(prices[i], mini);
            best = max(best, prices[i] - mini);
        }

        return best;
    }
};
