// Feb. 14th, 2025 (daily)

class Solution {
    public:
        int punishmentNumber(int n) {
            // 11^2 = 121, 12+1, or 1+2+1
            int sum = 1;
    
            for (int i = 2; i<=n; ++i) {
                if (validate(to_string(i*i), 0, i, 0)) sum += i*i;
            }
    
            return sum;
        }
    
        bool validate(const string& s, int index, int target, int currSum) {
    
            if (index == s.size()) return currSum == target;
    
            int num = 0;
            for (int i = index; i<s.size(); ++i) {
                num = num*10 + (s[i]-'0');
    
                if (num > target) break;
    
                if (validate(s, i+1, target, currSum + num)) return true;
            }
    
            return false;
        }
    };
    
    
    
            // string s = to_string(val);
            // queue<vector<int>> partCombs;
            // int starting = 10;
            // int div = 10;
    
            // while (val%div != val) {
            //     vector<int> currComb;
            //     currComb.push()
            //     partCombs.push(currComb);
            // }