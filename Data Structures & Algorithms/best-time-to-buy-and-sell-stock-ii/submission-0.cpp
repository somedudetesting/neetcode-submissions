class Solution {
public:
    int rec(vector<int>& prices, int i, int n, bool stock, int res) {
        if (i >= n - 1) return res;
        
        int diff = prices[i + 1] - prices[i];
        if (diff > 0) {
            res += diff;
        }
        return rec(prices, i + 1, n, stock, res);
    }
public:
    int maxProfit(vector<int>& prices) {
        return rec(prices, 0, prices.size(), false, 0);
    }
};