class Solution {
private:
    map<char, set<char>> uf;

    char findRep(const char& c) {
        for (auto& [rep, group] : uf) {
            if (group.count(c)) return rep;
        }
        return c; // not in any group yet
    }

    void union_(const char& c1, const char& c2) {
        char rep1 = findRep(c1);
        char rep2 = findRep(c2);

        if (rep1 == rep2) return;

        // always keep the lex smaller rep
        char newRep = min(rep1, rep2);
        char oldRep = max(rep1, rep2);

        uf[newRep].insert(uf[oldRep].begin(), uf[oldRep].end());
        uf[newRep].insert(c1);
        uf[newRep].insert(c2);
        uf.erase(oldRep);
    }

    bool find_(const char& c1, const char& c2) {
        return findRep(c1) == findRep(c2);
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // populate the union find with union
        for (int i=0; i<s1.length(); ++i) {
            // char c1=s1[i], c2=s2[i];
            // if (c1<c2) union_(c1,c2);
            // else union_(c2,c1);
            union_(s1[i],s2[i]);
        }

        // for (auto [g,l] : uf) {
        //     for (char c : l) {
        //         cout << c << " ";
        //     }
        //     cout << endl;
        // }

        // use find to engineer smallest string
        string res;
        for (const char& b : baseStr) {
            bool found=false;
            for (auto group : uf) {
                char rep = group.first;
                if (find_(rep, b)) {
                    res.push_back(rep);
                    found=true;
                    break;
                }
            }
            if (!found) res.push_back(b);
        }

        return res;
    }
};