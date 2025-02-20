// Feb. 18th, 2025 (daily)

class Solution {
    public:
        string getHappyString(int n, int k) {
            vector<char> letters = {'a','b','c'};
    
            vector<string> happys;
    
            for (int i = 0; i<3; ++i) {
                string happy(1, letters[i]);
                backtrack(happy, i, letters, n, happys);
            }
    
            return (k-1 >= happys.size()) ? "" : happys[k-1];
        }
    
        void backtrack(string& res, int& idx, const vector<char>& letters, const int& n, vector<string>& happys) {
            if (res.size() == n) {
                happys.push_back(res);
                return;
            }
    
            for (int i = 0; i<3; ++i) {
                if (i == idx) continue;
                res.push_back(letters[i]);
                backtrack(res, i, letters, n, happys);
                res.pop_back();
            }
    
        }
    };