class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int val : nums) {
            res ^= val;
        }
        return res;   
    }
};
