// Feb. 6th, 2025 (daily)

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {

        unordered_map<int, int> colorCnt;
        unordered_map<int, int> ballToColor;

        int n = queries.size(), cnt = 0;
        vector<int> res(n, 0);

        int prevColor = 0, newColor = 0, ball = 0;
        for (int i = 0; i<n; ++i) {

            ball = queries[i][0];
            newColor = queries[i][1];
            prevColor = ballToColor[ball];

            // ball was already colored, update previous color cnt, check if colorCnt=0
            if (prevColor != 0 && !(--colorCnt[prevColor])) cnt--;

            // newColorCnt from 0 -> 1 so totalCnt++
            if (!colorCnt[newColor]) cnt++;

            ballToColor[ball] = newColor;
            colorCnt[newColor]++;
            res[i] = cnt;
        }

        return res;
    }
};





        // unordered_map<int, unordered_set<int>> colorTakenBy;
        // unordered_map<int, int> ballToColor;

        // int n = queries.size(), cnt = 0;
        // vector<int> res(n, 0);

        // int prevColor = 0, ball = 0, newColor = 0;
        // for (int i = 0; i<n; ++i) {

        //     ball = queries[i][0];
        //     newColor = queries[i][1];

        //     prevColor = ballToColor[ball];
        //     auto& color_balls = colorTakenBy[newColor]; // set of balls currently with newColor

        //     // ball was not colored before
        //     if (prevColor == 0) {
        //         if (color_balls.empty()) cnt++;
        //     }
        //     // ball was colored before (remove it from prev set)
        //     else {
        //         // prev color set is empty, so total cnt decrements
        //         auto& prevSet = colorTakenBy[prevColor];
        //         prevSet.erase(ball);
        //         if (prevSet.empty()) cnt--;

        //         // new color already has >=1 ball, so dont add to total cnt
        //         if (color_balls.empty()) cnt++;
        //     }

        //     res[i] = cnt;
        //     ballToColor[ball] = newColor;
        //     color_balls.insert(ball);
        // }

        // return res;