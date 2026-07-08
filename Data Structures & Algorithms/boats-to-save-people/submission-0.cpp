class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int l = 0, r = people.size() - 1;

        int res = 0;
        while (l <= r) {
            int weight = people[l] + people[r];
            if (weight <= limit) {
                res++;
                l++;
                r--;
            } else if (weight > limit) {
                res++;
                r--;
            }
        }

        return res;
    }
};