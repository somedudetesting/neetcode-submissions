class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prevSumCount;
        // Base Condition, needs to be added since left of array is empty and if sum - k = 0 then this will be hit.
        prevSumCount[0] = 1;

        int sum = 0;
        int res = 0;
        for (int val : nums) {
            sum += val;
            if (prevSumCount.count(sum - k)) {
                res += prevSumCount[sum - k];
            }
            prevSumCount[sum]++;
        }

        return res;
    }
};