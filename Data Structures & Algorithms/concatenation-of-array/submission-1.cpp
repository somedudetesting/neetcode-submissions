class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(nums.begin(), nums.end());
        for (int val : nums) {
            ans.push_back(val);
        }

        return ans;
    }
};