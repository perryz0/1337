// Jan. 26th, 2025 (daily)

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        // int m = prerequisites.size();

        // vector<pair<int, int>> indegs(numCourses);  // {first: indeg, second: courseNum}
        vector<int> indegs(numCourses, 0);
        vector<int> adj[100];

        // prep for toposort
        // for (int i = 0; i < numCourses; ++i) indegs[i].second = i;
        for (auto& pre : prerequisites) {
            indegs[pre[1]]++;
            adj[pre[0]].push_back(pre[1]);
        }
        // sort(indegs.begin(), indegs.end());

        // toposort (kahn's)
        queue<int> q;
        // vector<bool> visited(numCourses, false);
        // int iter = 0;
        for (int i = 0; i < numCourses; ++i) if (indegs[i] == 0) q.push(i);

        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int i : adj[node]) {

                reachable[node][i] = true;
                for (int j = 0; j < numCourses; ++j) if (reachable[j][node]) reachable[j][i] = true;

                if (--indegs[i] == 0) q.push(i);
            } 
        }

        int n = queries.size();
        vector<bool> answer(n, false);

        for (int i = 0; i < n; ++i) answer[i] = reachable[queries[i][0]][queries[i][1]];

        return answer;
    }
};