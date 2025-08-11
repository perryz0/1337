// Aug 8th, 2025

class Solution {
private:
    vector<bool> used;
    int len;
    string N;

    bool check(int cand) {
        return cand > 0 && ((cand & (cand-1)) == 0);
    }

    bool dfs(string curr) {
        if (curr.length() == len) {
            if (check(stoi(curr))) return true;
        }
        bool seen[10] = {false};
        for (int i = 0; i < len; ++i) {
            if (used[i]) continue;
            int d = N[i]-'0';
            if (seen[d]) continue;
            if (curr.empty() && d == 0) continue; // no leading zero
            seen[d] = true;

            used[i] = true;
            curr.push_back(N[i]);
            if (dfs(curr)) return true;
            curr.pop_back();
            used[i] = false;
        }
        return false;
    }

public:
    bool reorderedPowerOf2(int n) {
        if (n==1e9) return false;
        // 9! = 362880 perms
        // string num = to_string(n);
        N=to_string(n);
        len = N.length();
        used = vector<bool>(len, false);

        return dfs("");
    }
};