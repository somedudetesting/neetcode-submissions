class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> rows, cols;
        map<pair<int, int>, unordered_set<int>> squares;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int val = board[i][j];
                pair<int, int> key = {i / 3, j / 3};

                if (rows[i].count(val) || cols[j].count(val) || squares[key].count(val)) {
                    return false;
                }

                rows[i].insert(val);
                cols[j].insert(val);
                squares[key].insert(val);
            }
        }

        return true;
    }
};
