class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n + 1);

        prefixSum[0] = 0;

        for (int i = 1; i < n + 1; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        int res = n + 1;

        for (int i = 0; i < n; i++) {
            int l = i, r = n;
            while (l < r) {
                int m = (l + r) / 2;

                int sum = prefixSum[m + 1] - prefixSum[i];
                if (sum >= target) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            if (l != n) {
                res = min(res, (l - i + 1));
            }
        }

        return res % (n + 1);
    }
};