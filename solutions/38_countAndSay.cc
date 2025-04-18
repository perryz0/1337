// Apr. 17th, 2025 (daily)

class Solution {
    public:
        string countAndSay(int n) {
            return rle(n-1, "1");
        }
    
        string rle(int x, const string& s) {
            if (x == 0) return s;
    
            string res;
            int i = 0;
    
            while (i<s.length()){
                int cnt=1;
                while (i+1<s.length() && s[i] == s[i+1]) {
                    cnt++;
                    i++;
                }
    
                res += to_string(cnt) + s[i];
                i++;
            }
    
            return rle(x-1, res);
        }
    };