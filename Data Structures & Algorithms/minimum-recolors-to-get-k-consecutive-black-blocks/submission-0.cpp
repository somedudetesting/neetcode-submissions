class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l = 0, r = 0;
        int res = blocks.size() + 1;

        int countB = 0;
        int countW = 0;
        while (r < blocks.size()) {
            if (blocks[r] == 'B') {
                countB++;
            } else {
                countW++;
            }
            r++;

            while (l < r && (countW + countB) >= k) {
                res = min(res, countW);
                if (blocks[l] == 'B') {
                    countB--;
                } else {
                    countW--;
                }
                l++;
            }
        }

        return res;
    }
};