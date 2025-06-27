// June 26th, 2025 (close)

class Solution {
private:
    string str;
    int kk;

    bool check(const string& sub) {
        int j=0, count=0;
        for (char c : str) {
            if (c == sub[j]) {
                ++j;
                if (j == sub.size()) {
                    ++count;
                    if (count == kk) return true;
                    j=0;
                }
            }
        }
        return false;
    }

public:
    string longestSubsequenceRepeatedK(string s, int k) {
        str=s;
        kk=k;

        vector<int> freq(26, 0);
        for (char c : s) freq[c-'a']++;

        string alphabet="";
        for (int i=25; i>=0; --i) {
            if (freq[i] >= k) alphabet += static_cast<char>(i+'a');
        }

        queue<string> q;
        q.push("");
        string best="";
        int maxLen=min((int)s.size()/k, 7);

        while (!q.empty()) {
            string cur=q.front(); q.pop();
            for (char c : alphabet) {
                string next=cur+c;
                if (check(next)) {
                    if (next.size() > best.size() || (next.size() == best.size() && next > best)) {
                        best=next;
                    }
                    if (next.size() < maxLen) {
                        q.push(next);
                    }
                }
            }
        }

        return best;
    }
};




// class Solution {
// private:
//     vector<queue<int>> f;
//     string str;
//     int kk;

//     string backtrack(int l, int r, string sub, vector<queue<int>> newIndices) {
//         // vector<int> temp=f;
//         // int curLen = 1;
//         // sliding window
//         for (int i=l; i<r; ++i) {
//             // newFreqs[str[i]-'a']--;
//             newIndices[str[i]-'a'].pop();
//         }
//         for (int i=25; i>=0; --i) {
//             if (newIndices[i].size() >= kk) {
//                 sub.push_back(static_cast<char>(i+'a'));
//                 backtrack(r, newIndices[i].front(), sub, newIndices);
//                 sub.pop_back();
//             }
//         }

//         return sub;
//     }

// public:
//     string longestSubsequenceRepeatedK(string s, int k) {
//         int n=s.length();
//         str=s;
//         kk=k;

//         // def dp
//         // max(ans) = floor(n/k)

//         // greedily form subsequences starting from the lexicographically largest?
//         // starting letter must appear >= k times, otherwise impossible
//         // vector<int> f(26,0);    // for debugging
//         // vector<unordered_set<int>> idxs(26);
//         // vector<int> first(26,-1);


//         f.assign(26, {});
//         // first.assign(26, -1);
//         for (int i=0; i<n; ++i) {
//             f[s[i]-'a'].push(i);
//             // idxs[s[i]-'a'].insert(i);
//             // if (first[s[i]-'a'] != -1) first[s[i]-'a']=i;
//         }

//         // for (int i=0; i<26; ++i) {
//         //     cout << static_cast<char>(i+'a') << " " << f[i].size() << ", ";
//         // }
//         // cout << endl;

//         // scan thru freqs from lexico largest
//         string ans;
//         for (int i=25; i>=0; --i) {
//             if (f[i].size() >= k) {
//                 ans = max(ans, backtrack(0, f[i].front(), to_string(i+'a'), f));
//             }
//         }

//         return ans;
//     }
// };






        // // scan thru freqs from lexico largest
        // for (int i=25; i>=0; --i) {
        //     if (f[i] >= k) {
        //         // for (const char& idx : idxs[i]) {
        //         //     // dfs(idx, ) // dont actually need to generate

        //         // }
        //     }
        // }