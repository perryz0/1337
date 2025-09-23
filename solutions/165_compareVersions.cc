// Sep. 22nd, 2025

class Solution {
public:
    int compareVersion(string version1, string version2) {
        std::istringstream i1(version1), i2(version2);
        string t1, t2;
        vector<int> v1,v2;
        while (getline(i1, t1, '.')) {
            v1.push_back(stoi(t1));
        }
        while (getline(i2, t2, '.')) {
            v2.push_back(stoi(t2));
        }

        int maxLen=max(v1.size(), v2.size());
        for (int i=v1.size(); i<maxLen; ++i) v1.push_back(0);
        for (int i=v2.size(); i<maxLen; ++i) v2.push_back(0);

        for (int i=0; i<maxLen; ++i) {
            if (v1[i] < v2[i]) return -1;
            else if (v1[i] > v2[i]) return 1;
        }

        return 0;
    }
};