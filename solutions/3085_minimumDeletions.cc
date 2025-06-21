// June 20th, 2025 (daily)

#include <algorithm>

class Solution {
public:
    int minimumDeletions(string word, int k) {
        // buildmaxheap of maxchars
        // pop until heap.top()-min = k
        vector<int> f(26,0);
        for (const char& c : word) f[c-'a']++;
        // int mn=f[0];
        // for (const int& fr : f) {
        //     if (fr == 0) continue;
        //     mn=min(mn, fr);
        //     cout << mn << endl;
        // }

        int ans=INT_MAX;
        for (int i=0; i<26; ++i) {
            if (f[i]==0) continue;
            int cur = 0;
            for (int j=0; j<26; ++j) {
                if (i==j || f[j]==0) continue;
                if (f[j] < f[i]) cur+=f[j];
                else if (f[j] > f[i]+k) cur+=(f[j]-f[i]-k);
            }
            // cout << "curr char: " << static_cast<char>(i+'a') << ", dels: " << cur << endl;
            ans=min(ans, cur);
        }

        return ans;

        // priority_queue<int> pq; // {freqs, letter}, nvm only freqs lol
        // for (int i=0; i<26; ++i) {
        //     if (f[i] == 0) continue;
        //     pq.push(f[i]);
        // }
        // // std::make_heap(f.begin(), f.end());

        // int ans=0;
        // while (!pq.empty() && pq.top()-mn > k) {
        //     int currFreq = pq.top(); pq.pop();
        //     ans += (currFreq - k);
        // }

        // return ans;
    }
};