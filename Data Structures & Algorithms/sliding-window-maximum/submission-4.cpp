class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> heap;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            heap.push({nums[i], i});
            if (i + 1 >= k) {
                while (heap.top().second <= i - k) {
                    heap.pop();
                }
                res.push_back(heap.top().first);
            }
        }

        return res;
    }
};
