// Sep. 10th, 2025

class Solution {
public:
    string sortVowels(string s) {
        // bucketsort
        vector<int> f(256, 0);
        int n=s.length();
        string vows="AEIOUaeiou";
        for(int i=0;i<n;++i){
            if(vows.find(s[i]) != string::npos) f[s[i]]++;
        }

        string ans;
        int ptr=0;
        for (int i=0; i<n; ++i) {
            char c=s[i];
            if (vows.find(c) != string::npos) {
                //advance the charptr
                while (f[ptr] == 0) {
                    ++ptr;
                }
                ans += static_cast<char>(ptr);
                f[ptr]--;
            } else {
                ans += c;
            }
        }

        return ans;
    }
};




// class Solution {
// public:
//     string sortVowels(string s) {
//         // vector<pair<int,int>> v;
//         vector<int> v;
//         int n = s.length();
//         string vows="aeiouAEIOU";
//         for(int i=0;i<n;++i){
//             // if(vows.find(s[i]) != string::npos) v.push_back({s[i],i});
//             if(vows.find(s[i]) != string::npos) v.push_back(s[i]);
//         }

//         sort(v.begin(), v.end());

//         string ans;
//         int ptr=0;

//         for (int i=0;i<n;++i){
//             if (vows.find(s[i]) != string::npos) {
//                 ans.push_back(v[ptr++]);
//             }
//             else {
//                 ans.push_back(s[i]);
//             }
//         }

//         return ans;
//     }
// };