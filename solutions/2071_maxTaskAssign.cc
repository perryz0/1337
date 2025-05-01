// Apr. 30th, 2025 (daily)

class Solution {
private:
    vector<int> t, w;

public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        t=tasks;
        w=workers;

        // binsearch
        int l = 1, r = min(n,m), ans = 0;
        while (l <= r) {
            int mid = l+(r-l)/2;
            if (check(mid, pills, strength)) {
                ans = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        return ans;
    }

    bool check(int mid, int pills, int strength) {
        multiset<int> ws(w.end()-mid, w.end());
        int p = pills;

        for (int i = mid-1; i>=0; --i) {
            int task = t[i];
            auto it = prev(ws.end());
            if (*it >= task) {
                ws.erase(it);
            } else {
                if (p == 0) return false;
                auto it2 = ws.lower_bound(task - strength);
                if (it2 == ws.end()) return false;
                ws.erase(it2);
                --p;
            }
        }

        return true;
    }
};