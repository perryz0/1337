// Sep. 9th, 2025

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int M=languages.size();
        vector<unordered_set<int>> langs(M, unordered_set<int>());
        for (int i=0; i<M; ++i) {
            langs[i] = unordered_set<int>(languages[i].begin(), languages[i].end());
        }

        unordered_set<int> isolated;

        // unordered_map<int,int> groups;
        for (const auto& vec : friendships) {
            int u=vec[0], v=vec[1];
            bool canSpeak=false;
            for (const int& l : langs[u-1]) {
                if (langs[v-1].empty()) break;
                if (langs[v-1].contains(l)) {
                    canSpeak=true;
                    break;
                }
            }
            if (canSpeak) continue;
            // otherwise these people are isolated, then greedily decide whats the best to teach
            isolated.insert(u);
            isolated.insert(v);
        }

        if (isolated.empty()) return 0;

        // start teaching
        // len(isolated) = total students
        vector<int> learnCnt(n+1, 0);
        for (const int& s : isolated) {
            for (int j=1; j<=n; ++j) {
                if (!langs[s-1].contains(j)) learnCnt[j]++;
            }
        }

        int ans=INT_MAX;
        for (int i=1; i<=n; ++i) ans=min(ans,learnCnt[i]);

        return ans;
    }
};