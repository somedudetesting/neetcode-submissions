#define ll long long

class Solution {
    vector<vector<int>> res;
    vector<int> quad;

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        rec(nums, 4, 0, (ll) target);
        return res;
    }

public: 
    void rec(vector<int>& nums, int k, int start, ll target) {
        if (k == 2) {
            int l = start, r = nums.size() - 1;
            while (l < r) {
                ll sum = (ll) nums[l] + nums[r];
                if (sum == target) {
                    quad.push_back(nums[l]);
                    quad.push_back(nums[r]);
                    res.push_back(quad);
                    quad.pop_back();
                    quad.pop_back();
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                } else if (sum < target) {
                    l++;
                } else {
                    r--;
                }
            }
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            quad.push_back(nums[i]);
            rec(nums, k - 1, i + 1, target - nums[i]);
            quad.pop_back();
        }
    }
};