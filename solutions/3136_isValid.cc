// July 14th, 2025

class Solution {
    public:
        bool isValid(string word) {
            if (word.length()<3) return false;
            bool v=false, co=false;
            string vows="aeiouAEIOU";
            // unordered_set<char> vows = {'a','e','i','o','u','A','E','I','O','U'};
            for (const char& c : word) {
                if (!(c-'0' >= 0 && c-'0' <= 9) && !(c-'a' >= 0 && c-'a'<26) && !(c-'A' >= 0 && c-'A'<26)) return false;
                if (c-'a' >= 0 && c-'a'<26) {
                    if (vows.find(c) != string::npos) v=true;
                    else co=true;
                }
                else if (c-'A' >= 0 && c-'A'<26) {
                    if (vows.find(c) != -1) v=true;
                    else co=true;
                }
            }
    
            return (v&&co);
        }
    };