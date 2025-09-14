// Sep. 13th, 2025

class Solution {
private:
    string v;
    unordered_set<string> exactMatches;
    unordered_map<string,string> capErrors, vowErrors;

    string convert(const string& s) {
        string agnostic;
        for (const char& c : s) {
            if (v.find(c) == string::npos) agnostic += c;
            else agnostic += '*';
        }

        return agnostic;
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        v = "aeiou";
        for (const string& w : wordlist) {
            // convert to vowel agnostic
            exactMatches.insert(w);

            string lower = w;
            std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            if (!capErrors.contains(lower)) capErrors[lower]=w;
            

            string agnostic = convert(lower);
            if (!vowErrors.contains(agnostic)) vowErrors[agnostic]=w;   // only need to use the first such match, dont overwrite
            // cout << "word: " << w << ", agnostic: " << agnostic << endl;
        }

        vector<string> ans;
        for (string s : queries) {
            // check based on precedence
            if (exactMatches.contains(s)) {
                ans.push_back(s);
                continue;
            }

            std::transform(s.begin(), s.end(), s.begin(), ::tolower);
            if (capErrors.contains(s)) {
                ans.push_back(capErrors[s]);
                continue;
            }

            // vow error case
            string agnosticQuery = convert(s);
            // cout << "original is: " << s << ", converted to: " << agnosticQuery << endl;
            if (vowErrors.contains(agnosticQuery)) ans.push_back(vowErrors[agnosticQuery]);
            
            // no match
            else ans.push_back("");
        }

        return ans;
    }
};