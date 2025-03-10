// Mar. 9th, 2025 (daily)

#define ll long long

class Solution {
private:
    unordered_set<char> vowels = {'a','e','i','o','u'};

public:
    long long solve(string& word, int k) {
        unordered_map<char, int> vcnts;
        
        int n = word.length();
        int slotOut = 0;
        ll ccnts = 0, res = 0;
        
        for (int i = 0; i < n; i++) {
            if (vowels.find(word[i]) != vowels.end()) {
                vcnts[word[i]]++;
            } else {
                ccnts++;
            }

            while (vcnts.size() == 5 && ccnts >= k) {
                if (vowels.find(word[slotOut]) != vowels.end()) {
                    vcnts[word[slotOut]]--;
                    
                    if (vcnts[word[slotOut]] == 0) {
                        vcnts.erase(word[slotOut]);
                    }
                } else {
                    ccnts--;
                }
                
                slotOut++;
            }
            
            res += slotOut;
        }
        
        return res;
    }
    
    long long countOfSubstrings(string word, int k) {

        // o(n) solve for AT LEAST k and AT LEAST k+1, remove their intersection for EXACTLY k
        return solve(word, k) - solve(word, k + 1);
    }
};












// TLE......... sdga kgljkadnikgdfb
// #define ll long long

// class Solution {

// private:
//     unordered_set<char> vowels = {'a','e','i','o','u'};
//     unordered_map<char, int> vcnts; // {a: >=1, e: >=1, i: >=1, o: >=1, u: >=1, $: =k}

// public:
//     long long countOfSubstrings(string word, int k) {
//         // window len: not fixed. # vows + k.
//         // if # cons > k, MUST MOVE L.
//         // if 
        
//         int n = word.length();

//         // for (auto& vow : vowels) {
//         //     vcnts[vow] = -1;
//         // }

//         // vcnts['$'] = -1;

//         for (int i = 0; i<5+k; ++i) {
//             char& c = word[i];
//             if (vowels.find(c) != vowels.end()) vcnts[c]++;
//             else vcnts['$']++;
//         }

//         ll cnt = 0;
//         if (isValidSubstr(vcnts, k)) cnt++;

//         int slotOut = 0;
//         // int slotIn = 5+k;

//         // sliding window
//         for (int i = 5+k; i<n; ++i) {

//             cout << "curr window RIGHT: " << i << endl;

//             // int& slotIn = i;
//             if (vowels.find(word[i]) != vowels.end()) {
//                 vcnts[word[i]]++;
//             } else {
//                 vcnts['$']++;
//             }

//             // check current window is valid
//             if (isValidSubstr(vcnts, k)) {
//                 cout << "slotOut: " << slotOut << ", valid substring: " << word.substr(slotOut) << endl;
//                 // yes, so we greedily advance LEFT to see if we can find more valid substrs
//                 cnt++;
//                 int l = slotOut+1;
//                 while (isValidSubstr(vcnts, k)) {
//                     if (vowels.find(word[l]) != vowels.end()) {
//                         vcnts[word[l]]--;
//                     } else {
//                         vcnts['$']--;
//                     }
//                     cnt++;
//                     l++;
//                 }
//             }
            
//             // only condition to advance LEFT permanently.
//             else if (vcnts['$'] > k) {
//                 while (vcnts['$'] > k) {
//                     if (vowels.find(word[slotOut]) == vowels.end()) {
//                         vcnts['$']--;
//                     } else {
//                         vcnts[word[slotOut]]--;
//                     }
//                     slotOut++;
//                 }
//             }
//         }

//         return cnt;
//     }

//     bool isValidSubstr(unordered_map<char, int>& freqs, const int& k) {
//         for (auto& vow : vowels) {
//             cout << vow << ": " << freqs[vow] << endl;
//             if (freqs[vow] == 0) return false;
//         }

//         cout << "consonant: " << freqs['$'] << endl;
//         return freqs['$'] == k;
//     }
// };