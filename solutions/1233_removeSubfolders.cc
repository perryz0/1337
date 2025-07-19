// July 18th, 2025

class Solution {
private:
    unordered_set<string> goodFolders;

    void dfs(int curIdx, string folder) {
        if (curIdx == 0) {
            goodFolders.insert(folder);
            return;
        }

        if (goodFolders.contains(folder.substr(0, curIdx))) return;
        
        // otherwise keep going up
        --curIdx;
        while (folder[curIdx] != '/') {
            curIdx--;
        }

        dfs(curIdx, folder);
    }

public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        goodFolders.clear();

        for (string& f : folder) {
            dfs(f.length(), f);
        }

        vector<string> ans(goodFolders.begin(), goodFolders.end());

        return ans;
    }
};