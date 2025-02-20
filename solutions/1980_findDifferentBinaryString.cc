// Feb. 19th, 2025 (daily)

class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            unordered_set<string> cands;
    
            for (int i = 0; i<=1; ++i) {
                string curr(1, i+'0');
                backtrack(cands, curr, nums[0].length());
            }
    
            for (string& num : nums) cands.erase(num);
    
            for (auto& cand : cands) return cand;
    
            return "";
        }
    
        void backtrack(unordered_set<string>& cands, string& curr, const int& target) {
            if (curr.length() == target) {
                cands.insert(curr);
                return;
            }
    
            for (int i = 0; i<=1; ++i) {
                curr.push_back('0'+i);
                backtrack(cands, curr, target);
                curr.pop_back();
            }
        }
    };