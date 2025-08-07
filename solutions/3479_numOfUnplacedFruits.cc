// Aug 5th, 2025

// sqrt decomp, editorial

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        int m = sqrt(n);
        int section = (n + m - 1) / m;
        int count = 0;
        vector<int> maxV(section);
        for (int i = 0; i < n; i++) {
            maxV[i / m] = max(maxV[i / m], baskets[i]);
        }
        for (int fruit : fruits) {
            int sec;
            int unset = 1;
            for (sec = 0; sec < section; sec++) {
                if (maxV[sec] < fruit) {
                    continue;
                }
                int choose = 0;
                maxV[sec] = 0;
                for (int i = 0; i < m; i++) {
                    int pos = sec * m + i;
                    if (pos < n && baskets[pos] >= fruit && !choose) {
                        baskets[pos] = 0;
                        choose = 1;
                    }
                    if (pos < n) {
                        maxV[sec] = max(maxV[sec], baskets[pos]);
                    }
                }
                unset = 0;
                break;
            }
            count += unset;
        }
        return count;
    }
};





// READ THE PROBLEM WRONG LOL

// class Solution {
// public:
//     int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
//         int n=fruits.size();
//         int ans=n;

//         // each basket is committed to a single type of fruit
//         // iterate through fruits left to right, so the order REMAINS for fruits
//         // binary search on the baskets (basket order does not matter)
//         // mark each basket filled when commited
//         // sort(baskets.begin(), baskets.end());
//         // vector<bool> commited(n,0);
//         set<int> available(baskets.begin(), baskets.end()); // use ordered_set instead for logn deletions

//         for (const int& f : fruits) {
//             auto basketPTR = available.lower_bound(f);

//             // no avai basket can fit
//             if (basketPTR == available.end()) continue;

//             // otherwise found, commit and delete
//             cout << "commited basket has " << *basketPTR << " slots" << endl;
//             available.erase(basketPTR);
//             --ans;
//         }

//         return ans;
//     }
// };