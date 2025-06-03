// June 2nd, 2025 (daily)

class Solution {
private:
    unordered_set<int> ak;  // available/found keys
    vector<bool> vis;
    // vector<int> maxes;      // max # of candies found when we get to box[i]
    unordered_set<int> ab;  // available boxes

public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=status.size();
        vis.assign(n, false);

        // start bfs from the initial boxes
        queue<int> q;
        for (const int& b : initialBoxes) {
            q.push(b);
            ab.insert(b);
            // add all the found keys for box[i]
            for (int& k : keys[b]) {
                ak.insert(k);
            }
            // add all the found boxes
            for (int& nb : containedBoxes[b]) {
                ab.insert(nb);
            }
        }

        for (int i=0; i<n; ++i) {
            if (status[i] == 1) {
                ak.insert(i);
                // ab.insert(i);
            }
        }

        int ans=0;
        while (!q.empty()) {
            int curr = q.front();
            // cout << "curr: " << curr << endl;
            q.pop();
            if (!ak.contains(curr) || vis[curr] || !ab.contains(curr)) {
                // q.push(curr);
                continue;
            }
            vis[curr] = true;
            ans += candies[curr];
            ab.erase(curr);
            ak.erase(curr);

            // add to queue for box traversal
            for (int& nb : containedBoxes[curr]) {
                ab.insert(nb);
                if (ak.contains(nb)) q.push(nb);
            }

            // add keys for access
            for (int& k : keys[curr]) {
                ak.insert(k);
                if (ab.contains(k)) q.push(k);
            }
        }

        return ans;
    }
};





        // int n=status.size();
        // vis.assign(n, false);
        // // maxes.assign(n, 0);

        // // start bfs from the initial boxes
        // queue<pair<int,int>> q;
        // for (const int& b : initialBoxes) {
        //     q.push({b, b});
        //     // add all the found keys for box[i]
        //     for (int& k : keys[b]) {
        //         ak.insert(k);
        //     }
        // }

        // for (int i=0; i<n; ++i) if (status[i] == 1) ak.insert(i);

        // // int prevpb = -1;
        // int ans=0;
        // while (!q.empty()) {
        //     auto [cb, pb] = q.front();
        //     cout << cb << ", " << pb << endl;
        //     // if (pb != -1) cout << maxes[pb] <<  "," << candies[cb] << endl;
        //     q.pop();
        //     if (!ak.contains(cb) || vis[cb]) continue;
        //     vis[cb] = true;
        //     ans += candies[cb];
            
        //     // maxes[cb] = maxes[pb] + candies[cb];

        //     // add keys for access
        //     for (int& k : keys[cb]) {
        //         ak.insert(k);
        //         // q.push({k,cb});
        //     }

        //     // add to queue for box traversal
        //     for (int& nb : containedBoxes[cb]) {
        //         q.push({nb,cb});
        //     }
        // }

        // // int ans=0;
        // // for (const int& m : maxes) {
        // //     cout << m << " ";
        // //     ans=max(ans,m);
        // // }

        // return ans;