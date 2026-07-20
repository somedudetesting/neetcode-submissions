class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int res = INT_MAX;


        int l = 1, r = *max_element(piles.begin(), piles.end());

        while (l <= r) {
            int k = (l + r) / 2;

            long long timeTaken = 0;
            for (int p : piles) {
                timeTaken += ceil((double) p / k);
            }
            if (timeTaken <= h) {
                res = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }

        return res;
    }
};
