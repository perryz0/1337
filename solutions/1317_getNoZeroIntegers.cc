// Sep. 7th, 2025

class Solution {
private:
    bool check(const string& digits){
        bool valid=true;
        for (const char& c : digits) if (c=='0') { valid=false; break; }

        return valid;
    }

public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i=1; i<=n/2; ++i) {
            if (to_string(i).find('0') != string::npos) continue;
            int j=n-i; bool valid=true;
            // string digits=to_string(j);
            if (to_string(j).find('0') == string::npos) return {i,j};
        }

        return {};
    }
};