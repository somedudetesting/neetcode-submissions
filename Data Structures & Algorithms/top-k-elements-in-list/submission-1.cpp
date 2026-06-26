class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> bucket(nums.size() + 1);
        unordered_map<int, int> count;

        for (int num : nums) {
            count[num]++;
        }

        for (const auto& c : count) {
            bucket[c.second].push_back(c.first);
        }

        vector<int> res;
        for (int i = bucket.size() - 1; i >= 0 && k != 0; i--) {
            for (int val : bucket[i]) {
                res.push_back(val);
                k--;
            }
        }

        return res;
    }
};
