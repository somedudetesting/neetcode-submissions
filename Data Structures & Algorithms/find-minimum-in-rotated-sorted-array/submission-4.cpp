class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;

        int res = 1001;
        while (l <= r) {
            if (nums[l] < nums[r]) {
                return min(nums[l], res);
            }
            int mid = (r + l) / 2;

            res = min(res, nums[mid]);
            if (nums[l] <= nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }
};
