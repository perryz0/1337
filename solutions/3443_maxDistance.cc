// June 19th, 2025 (daily)

class Solution {
public:
    int maxDistance(string s, int k) {
        unordered_map<char,int> f;
        int runningMax=1;
        for (const char& dir : s) {
            f[dir]++;

            int mxv = max(f['N'],f['S']), mnv = min(f['N'],f['S']);
            int mxh = max(f['E'],f['W']), mnh = min(f['E'],f['W']);
            // cout << mxv << "," << mnv << endl;
            // cout << mxh << "," << mnh << endl;
            
            int curr=mxv+mxh;
            int additional = (k > mnv+mnh) ? mnv+mnh : k-(mnv+mnh-k);
            // cout << "additional:" << additional << endl;
            runningMax = max(runningMax, curr+additional);
            // cout << "curr RMAX: " << runningMax << endl;
        }

        return runningMax;
    }
};