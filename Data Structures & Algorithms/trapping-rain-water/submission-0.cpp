class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax(height.size());
        vector<int> rightMax(height.size());

        leftMax[0] = 0;
        int maxi = height[0];
        for (int i = 1; i < height.size(); i++) {
            maxi = max(maxi, height[i]);
            leftMax[i] = maxi;
        }

        rightMax[height.size() - 1] = 0;
        maxi = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0 ; i--) {
            maxi = max(maxi, height[i]);
            rightMax[i] = maxi;
        }


        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            int ans = min(leftMax[i], rightMax[i]) - height[i];
            res += max(ans, 0);
        }

        return res;
    }
};
