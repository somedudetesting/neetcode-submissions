#define ll long long

class Solution {
public:
    int arrangeCoins(int n) {
        /* since each row consists of i coins where 0 < i <= n; 
        it forms a natural number sequence 
        we can use the formula (k * (k + 1)) / 2 to get the coins for a mid value
        see if it is within n so no incomplete row, or exceeds n, so there will be incomplete row*/

        ll l = 1, r = n, res = 0;

        while (l <= r) {
            ll mid = l + (r - l) / 2;
            ll coins = (mid * (mid + 1)) / 2;
            if (coins > n) {
                r = mid - 1;
            } else {
                res = max(res, mid);
                l = mid + 1;
            }
        }

        return res;
    }
};