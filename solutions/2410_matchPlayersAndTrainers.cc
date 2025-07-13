// July 12th, 2025

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int t=0;
        int ans=0;
        for (const int& p : players) {
            while (t < trainers.size() && p > trainers[t]) {
                ++t;
            }
            if (t == trainers.size()) break;
            ++t;
            ans++;
            // if (t == trainers.size()) break;
        }

        return ans;
    }
};