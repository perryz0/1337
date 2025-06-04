// June 3rd, 2025 (daily)

class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;
        vector<vector<int>> indices(26);

        int n=word.length();

        for (int i=0; i<n; ++i) {
           indices[word[i]-'a'].push_back(i);
        //    cout << "letter " << word[i] << "; idx " << word[i]-'a' << ": " << i << endl;
        }

        // indices[letter] in increasing order (i.e., maximizing lexicography)

        // int start=-1;
        vector<int> starts;
        for (int i=25; i>=0; --i) {
            for (int j=0; j<indices[i].size(); ++j) {
                if (n-(indices[i][j]+1) >= (numFriends-1)-indices[i][j]) {
                    starts.push_back(indices[i][j]);
                    // break;
                }
            }
            // if (start != -1) break;
            if (!starts.empty()) break;
        }

        // for (int& s : starts) cout << s << endl;

        // find lex max from these start candidates
        string res;
        for (int i=0; i<starts.size(); ++i){
            string curr;
            for (int j=starts[i]; j<n-(numFriends-starts[i]-1) && j<n; ++j) {
                curr.push_back(word[j]);
            }
            res = max(res, curr);
        }

        return res;
    }
};