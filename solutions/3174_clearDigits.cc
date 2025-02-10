// Feb. 9th, 2025 (daily)

class Solution {
    public:
        string clearDigits(string s) {
            unordered_set<char> nums = {'0','1','2','3','4','5','6','7','8','9'};
    
            // stack<char> stk;    // stack of all the alpha chars
            string res;
            for (char& c : s) {
                if (nums.find(c) != nums.end()) res.pop_back();
                else res.push_back(c);
            }
    
            // string res;
            // res.resize(stk.size());
            // int i = stk.size()-1;
    
            // while (!stk.empty()) {
            //     res[i] = stk.top();
            //     stk.pop();
            //     i-=1;
            // }
    
            return res;
        }
    };