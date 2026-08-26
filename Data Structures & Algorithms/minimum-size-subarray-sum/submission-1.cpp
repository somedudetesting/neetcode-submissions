class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;

        int res = INT_MAX;
        int sum = 0;
        while (r < nums.size()) {
            sum += nums[r++];
            while (l <= r && sum >= target) {
                sum -= nums[l++];
                res = min((r - l + 1), res);
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};