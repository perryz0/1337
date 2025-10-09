// Oct. 8th, 2025

using ll = long long;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        // simulate everything?
        int N=skill.size(), M=mana.size();
        vector<vector<ll>> times(M, vector<ll>(N+1, 0));    // N+1 phases

        // first one is fixed
        for (int i=1; i<N+1; ++i) {
            times[0][i] = times[0][i-1] + (ll)mana[0]*skill[i-1];
        }

        // {1, 5, 2, 4}
        // {1, 6, 8, 12}

        // potions 1...M
        for (int i=1; i<M; ++i) {
            // first calculate ideal times start to finish, intermediate times dont matter. scheduling whole blocks here
            for (int j=1; j<N+1; ++j) {
                times[i][j] = times[i][j-1] + (ll)mana[i]*skill[j-1];
                // cout << times[i][j] <<  " " << endl;
            }

            // find the biggest gap with prev row
            ll GAP=0;
            for (int j=0; j<N; ++j) {
                if (GAP < (times[i-1][j+1] - times[i][j])) {
                    GAP=times[i-1][j+1] - times[i][j];
                    // IDX= // might not need this
                }
                // cout << "gap is now: " << GAP << endl;
            }

            // now normalize by that gap
            for (int j=0; j<N+1; ++j) times[i][j] += GAP;
        }

        return times[M-1][N];
    }
};