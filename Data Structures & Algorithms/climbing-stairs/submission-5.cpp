class Solution {
public:
    int climbStairs(int n) {
        int one = 1, two = 1;

        for (int i = 1; i <= n - 1; i++) {
            int tmp = one;
            one += two;
            two = tmp;
        }

        return one;
    }
};
