// Jan. 5th, 2025 (daily)

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res(boxes.length(), 0);

        int runningSum = 0;
        int rightBalls = 0;

        for (int i = 1; i < boxes.length(); ++i) {
            if (boxes[i] == '1') {
                runningSum += i;
                rightBalls++;
            }
        }

        res[0] = runningSum;
        int leftBalls = (boxes[0] == '1') ? 1 : 0;

        for (int i = 1; i < boxes.length(); ++i) {
            runningSum -= (1*rightBalls - 1*leftBalls);
            res[i] = runningSum;
            if (boxes[i] == '1') (rightBalls-- && leftBalls++);
        }

        return res;
    }
};





        // o(n^2)
        // vector<int> res(boxes.length());

        // for (int i = 0; i < boxes.length(); ++i) {
        //     int shifts = 0;
        //     for (int j = i-1; j >= 0; --j) {
        //         if (boxes[j] == '1') shifts+=(i-j);
        //     }

        //     for (int k = i+1; k < boxes.length(); ++k) {
        //         if (boxes[k] == '1') shifts+=(k-i);
        //     }

        //     res[i] = shifts;
        // }

        // return res;