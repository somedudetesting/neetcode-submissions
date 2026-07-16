class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        int l = 0, r = ROWS * COLS - 1;

        while (l <= r) {
            int mid = (l + r) / 2;

            int row = mid / COLS;
            int col = mid % COLS;

            if (matrix[row][col] > target) {
                r--;
            } else if (matrix[row][col] < target) {
                l++;
            } else {
                return true;
            }
        } 

        return false;
    }
};