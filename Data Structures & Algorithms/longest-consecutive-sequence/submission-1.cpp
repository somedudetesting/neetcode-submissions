class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seq(nums.begin(), nums.end());
        int res = 0;
                
        for (int val : seq) {
            if (seq.find(val - 1) == seq.end()) {
                int len = 1;
                while (seq.count(val + len)) {
                    len++;
                }
                res = max(len, res);
            }
        }
    
        return res;
    }
};
 