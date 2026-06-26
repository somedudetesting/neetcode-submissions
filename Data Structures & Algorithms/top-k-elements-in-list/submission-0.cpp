class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int val : nums) {
            freq[val]++;
        }

        vector<pair<int,int>> arr;
        for (auto& p : freq) {
            arr.push_back({p.second, p.first});
        }
        sort(arr.rbegin(), arr.rend());

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(arr[i].second);
        }

        return res;
    }
};
