// Jan. 3rd, 2025 (daily)

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, int> firstOccurrence;
        unordered_map<char, int> lastOccurrence;
        vector<unordered_set<char>> freqs(26);
        
        for (int i = 0; i < s.length(); ++i) {
            if (firstOccurrence.find(s[i]) == firstOccurrence.end()) {
                firstOccurrence[s[i]] = i;
            }
            lastOccurrence[s[i]] = i;
        }

        for (auto& entry : firstOccurrence) {
            char c = entry.first;
            int start = firstOccurrence[c];
            int end = lastOccurrence[c];
            
            if (end > start + 1) {
                for (int i = start + 1; i < end; ++i) {
                    freqs[c - 'a'].insert(s[i]);
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < 26; ++i) {
            cnt += freqs[i].size();
        }

        return cnt;
    }
};



                // if (i == chars[curr]+1) {
                //     freqs[curr-'a'].insert(curr);
                // } else if (i-chars[curr] > 1) {
                //     cout << "iteration " << i << ", curr: " << curr << ", letters inserted: ";
                //     for (auto& character : chars) {
                        
                //         if (character.second != -1 && character.first != curr) {
                //             cout << character.first;
                //             freqs[curr-'a'].insert(character.first);
                //         }
                        
                //     }
                //     cout << endl;
                // }

    // int countPalindromicSubsequence(string s) {
    //     unordered_map<char, int> chars;     // {char, idx of first occurrence}
    //     vector<bool> seen(26, false);
    //     vector<bool> valid(26, false);
    //     vector<unordered_set<char>> freqs(26);
    //     for (char c = 'a'; c <= 'z'; ++c) {
    //         chars[c] = -1;
    //     }
    //     chars[s[0]] = 0;
    //     seen[s[0]-'a'] = true;

    //     cout << "iteration 0: char is " << s[0] << ", idx at " << chars[s[0]] << endl;

    //     for (int i = 1; i < s.length(); ++i) {
    //         char curr = s[i];
            
    //         if (chars[curr] == -1) {
    //             cout << curr << " never existed, iteration: " << i << endl;
    //             chars[curr] = i;
    //             seen[curr-'a'] = true;
    //         }

    //         for (char c = 'a'; c <= 'z'; ++c) {
    //             if (seen[c-'a'] && i-2 >= 0 && s[i-2] != curr) {
    //                 freqs[c-'a'].insert(curr);
    //             }
    //         }

    //         if (seen[curr-'a'] == true && i-chars[curr] >= 2) valid[curr-'a'] = true;
    //     }

    //     int cnt = 0;
    //     for (int i = 0; i < freqs.size(); ++i) {
    //         cout << freqs[i].size() << endl;
    //         if (valid[i]) cnt += freqs[i].size();
    //     }

    //     return cnt;
    // }