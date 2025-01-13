// Jan. 6th, 2025 (daily)

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {

        unordered_set<string> res_set;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words.size(); ++j) {
                if (i != j && words[i].find(words[j]) != string::npos) res_set.insert(words[j]);
            }
        }

        vector<string> res(res_set.size());
        int iter = 0;
        for (const string& validSub : res_set) {
            res[iter] = validSub;
            iter++;
        }

        return res;
    }
};



        // unordered_set<string> potential;

        // for (string& word : words) {
        //     potential.insert(word);
        // }

        // unordered_set<string> substrings;

        // for (string& word : words) {
        //     potential.erase(word);
        //     for (const string& candidate : potential) {
        //         if (word.find(candidate) != -1) {
        //             substrings.insert(candidate);
        //         }
        //     }
        //     potential.insert(word);
        // }

        // vector<string> res(substrings.size());

        // int iter = 0;
        // for (const string& sub : substrings) {
        //     res[iter] = sub;
        //     iter++;
        // }

        // return res;