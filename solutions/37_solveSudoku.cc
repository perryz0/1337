// Aug. 30, 2025

class Solution {
private:
    vector<vector<bool>> rows, cols;
    vector<vector<vector<bool>>> boxes;
    vector<pair<int,int>> available;
    vector<vector<char>> BOARD;
    bool solved = false;

    // void backtrack()

    void go(int idx) {
        if (idx == available.size()) {
            solved=true;    // end constriant
            return;
        }

        auto [x,y] = available[idx];
        int cx = x/3, cy = y/3;
        for (int c=0; c<9; ++c) {
            // already set
            if (rows[x][c] || cols[y][c] || boxes[cx][cy][c]) continue;

            // not set
            BOARD[x][y] = static_cast<char>(c+'1');
            rows[x][c] = true;
            cols[y][c] = true;
            boxes[cx][cy][c] = true;

            go(idx+1);
            if (solved) return;

            // unset to backtrack
            rows[x][c] = false;
            cols[y][c] = false;
            boxes[cx][cy][c] = false;
            BOARD[x][y]='.';
        }
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        BOARD=board;
        rows = vector<vector<bool>>(9, vector<bool>(9, false));
        cols = vector<vector<bool>>(9, vector<bool>(9, false));
        boxes = vector<vector<vector<bool>>>(3, vector<vector<bool>>(3, vector<bool>(9, false))); // DIV3 both dims for the boxID
        // vector<pair<int,int>> available;

        // add all available and mark set

        for (int r=0; r<9; ++r) {
            for (int c=0; c<9; ++c) {
                if (board[r][c] == '.') {
                    available.push_back({r,c});
                    continue;
                }
                int cellVal = board[r][c]-'1';  // {1..9}
                // if (rows[r][cellVal] || cols[c][cellVal] || boxes[r/3][c/3][cellVal]) {
                //     return false;
                // }
                // otherwise add to all constraint checkers
                rows[r][cellVal]=true;
                cols[c][cellVal]=true;
                boxes[r/3][c/3][cellVal]=true;
            }
        }

        go(0);

        board=BOARD;
    }
};