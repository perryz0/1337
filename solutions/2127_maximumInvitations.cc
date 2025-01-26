// Jan. 25th, 2025 (daily)
// couldnt solve this one lol

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        // neet solution
        int n = favorite.size();
        int longest = 0;
        vector<bool> visit(n, false);
        vector<pair<int, int>> lenTwos;

        // first find longest closed cycle
        for (int i = 0; i < n; ++i) {
            if (visit[i]) continue;

            int start = i, cur = i;
            unordered_set<int> cur_set;

            while (!visit[cur]) {
                visit[cur] = true;
                cur_set.insert(cur);
                cur = favorite[cur];
            }

            if (cur_set.find(cur) != cur_set.end()) {
                int length = cur_set.size();
                while (start != cur) {
                    length -= 1;
                    start = favorite[start];
                }
                longest = max(longest, length);
                if (length == 2) lenTwos.push_back({cur, favorite[cur]});
            }
        }

        // next find sum of longest open cycles (len = 2)
        unordered_map<int, vector<int>> invert;
        for (int i = 0; i < n; ++i) invert[favorite[i]].push_back(i);

        int open_sum = 0;
        for (auto& [n1, n2] : lenTwos) {
            open_sum += bfs(n1, n2, invert) + bfs(n2, n1, invert) + 2;
        }


        // ret the max of these two
        return max(longest, open_sum);
    }

    int bfs(int start, int parent, unordered_map<int, vector<int>>& invert) {
        queue<pair<int, int>> q;
        q.push({start, 0});
        int cur_max = 0;

        while (!q.empty()) {
            auto [cur, length] = q.front();
            q.pop();

            if (cur == parent) continue;

            cur_max = max(cur_max, length);

            for (auto& neighbor : invert[cur]) {
                q.push({neighbor, length + 1});
            }
        }

        return cur_max;
    }
};