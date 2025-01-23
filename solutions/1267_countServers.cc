// Jan. 23rd, 2025 (daily)

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        vector<int> rowCnts(rows, 0);
        vector<int> colCnts(cols, 0);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    rowCnts[i]++;
                    colCnts[j]++;
                }
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1 && (rowCnts[i] >= 2 || colCnts[j] >= 2)) cnt++;
            }
        }
        

        return cnt;
    }
};



        // ONE-PASS ATTEMPT (really bad idea lol, didnt work)
        // vector<int> col(250, 0);
        // vector<int> row(250, 0);

        // vector<pair<int, int>> colFirst(250);
        // vector<pair<int, int>> rowFirst(250);

        // for (int i = 0; i < rows; ++i) {
        //     for (int j = 0; j < cols; ++j) {
        //         if (grid[i][j] == 1) {

        //             if (row[i] == 0 && col[j] == 0) {
        //                 colFirst[j] = {i, j};
        //                 rowFirst[i] = {i, j};
        //             }

        //             if (col[j] == 1) { cnt += 2; row[colFirst[j].first]++; col[colFirst[j].second]++; row[i]=2; col[j]=2; continue; }

        //             if (row[i] == 1) { cnt += 2; row[rowFirst[i].first]++; col[rowFirst[i].second]++; row[i]=2; col[j]=2; continue; }


        //             if (col[j] > 0) {
        //                 if (col[j] != 1) cnt++;
        //                 row[i]++; col[j]++;
        //             } else if (row[i] > 0) {
        //                 if (row[i] != 1) cnt++;
        //                 row[i]++; col[j]++;
        //             }

        //             col[j]++;
        //             row[i]++;

        //         }
        //     }
        // }