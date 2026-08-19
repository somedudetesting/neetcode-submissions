class Solution {
private:
    unordered_map<int, int> mp;
    int dfs(int i, int n) {
        if (i == n) {
            return 1;
        } else if (i > n) {
            return 0;
        }

        if (mp.count(i)) {
            return mp[i];
        } 
        return mp[i] = dfs(i + 1, n) + dfs(i + 2, n);
    }
public:
    int climbStairs(int n) {
        return dfs(0, n);    
    }
};
