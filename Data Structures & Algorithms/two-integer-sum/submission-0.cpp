class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hm;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (hm.count(diff)) {
                return {hm[diff], i};
            }
            hm[nums[i]] = i;
        }

        return {};
    }
};
