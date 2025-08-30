// Aug. 29th, 2025

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<vector<bool>>> boxes(3, vector<vector<bool>>(3, vector<bool>(9, false))); // DIV3 both dims for the boxID

        for (int r=0; r<9; ++r) {
            for (int c=0; c<9; ++c) {
                if (board[r][c] == '.') continue;
                int cellVal = board[r][c]-'1';  // {1..9}
                if (rows[r][cellVal] || cols[c][cellVal] || boxes[r/3][c/3][cellVal]) {
                    return false;
                }
                // otherwise add to all constraint checkers
                rows[r][cellVal]=true;
                cols[c][cellVal]=true;
                boxes[r/3][c/3][cellVal]=true;
            }
        }


        return true;
    }
};