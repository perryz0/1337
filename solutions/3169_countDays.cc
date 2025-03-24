// Mar. 23rd, 2025 (daily)

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();

        vector<pair<int, int>> intervals(n);
        int it = 0;
        for (auto& meeting : meetings) {
            intervals[it] = {meeting[0], meeting[1]};
            it++;
        }

        sort(intervals.begin(), intervals.end());

        vector<pair<int, int>> merged;

        pair<int, int> curr = intervals[0];

        for (int i = 1; i<n; ++i) {

            // cout << "curr interval: " << intervals[i].first << ", " << intervals[i].second << endl;

            // no overlap case, we push curr tracking interval to the merged
            if (intervals[i].first > curr.second) {
                merged.push_back(curr);
                curr = intervals[i];
                continue;
            }

            // otherwise we just keep merging
            curr.second = max(curr.second, intervals[i].second);
        }

        // we missed the last merge, so we must push before processing
        merged.push_back(curr);

        int res = days;
        for (auto& [s, e] : merged) {   // start, end
            // cout << "start: " << s << ", " << "end: " << e << endl;
            res -= (e-s+1);
        }

        // int begin = intervals[0].first;
        // int res = days;
        // for (int i = 1; i<n; ++i) {
        //     if (intervals[i].first > begin) {
        //         for (int j = intervals[i-1].second; j>=intervals[i-1].first; --j) {
        //             res--;
        //         }
        //         begin = intervals[i].first;
        //     }
        // }

        // for (int j = intervals[n-1].second; j>=intervals[n-1].first; --j) {
        //     res--;
        // }

        return res;
    }
};