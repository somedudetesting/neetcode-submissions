class NumMatrix {
private:
    vector<vector<int>> nMatrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        nMatrix = vector<vector<int>>(ROWS+1, vector<int>(COLS+1, 0));
        for (int r = 0; r < ROWS; r++) {
            int prefix = 0;
            for (int c = 0; c < COLS; c++){
                prefix += matrix[r][c];
                int above = nMatrix[r][c+1];
                nMatrix[r+1][c+1] = prefix + above;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++, col1++, row2++, col2++;

        int bottomRight = nMatrix[row2][col2];
        int above = nMatrix[row1 - 1][col2];
        int left = nMatrix[row2][col1 - 1];
        int topLeft = nMatrix[row1 - 1][col1 - 1];

        return bottomRight - above - left + topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */