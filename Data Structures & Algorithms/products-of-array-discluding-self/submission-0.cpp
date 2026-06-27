class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;

        int zeroCount = 0;
        for (int val : nums) {
            if (val == 0) {
                zeroCount++;
                continue;
            }
            prod *= val;
        }


        if (zeroCount >= 2) return vector<int>(nums.size(), 0);

        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (zeroCount == 1) {
                if (nums[i] == 0) {
                    res[i] = prod;
                } else {
                    res[i] = 0;
                }
                continue;
            } 

            res[i] = prod / nums[i];
        }

        return res;
    }
};
