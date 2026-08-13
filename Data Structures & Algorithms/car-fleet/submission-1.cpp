class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> arr;

        for (int i = 0; i < speed.size(); i++) {
            arr.push_back({position[i], speed[i]});
        }

        sort(arr.begin(), arr.end());

        stack<pair<int, int>> stk;
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (!stk.empty()) {
                float timeTaken1 = (float) (target - stk.top().first) / stk.top().second;
                float timeTaken2 = (float) (target - arr[i].first) / arr[i].second;
                // cout << timeTaken1 << " " << timeTaken2;
                if (timeTaken1 < timeTaken2) {
                    stk.push(arr[i]);
                }
            } else {
                stk.push(arr[i]);
            }
        }

        return stk.size();
    }
};
