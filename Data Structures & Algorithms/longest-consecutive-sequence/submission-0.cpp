class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seq(nums.begin(), nums.end());
        int res = 0;
                
        for (int i = 0; i < nums.size(); i++) {
            if (seq.find(nums[i] - 1) == seq.end()) {
                int len = 1;
                while (seq.count(nums[i] + len)) {
                    len++;
                }
                res = max(len, res);
            }
        }
    
        return res;
    }
};
 