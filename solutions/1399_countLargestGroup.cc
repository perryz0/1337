// Apr. 22nd, 2025 (daily)

class Solution {
    // private:
    //     unordered_map<int,int> cnts;
    
    public:
        int countLargestGroup(int n) {
            //o(n) becuase n=10000 is o(5) each, so o(5n) worst case
            unordered_map<int,int> cnts;    // <digitsum : cnt>
            
            for (int i=1; i<=n; ++i) {
                // cnts[ds(i)]++;
                cnts[ds(i)]++;
            }
    
            int mx = 1;
            int mxcnt = 0;
            for (auto& [ds, sz] : cnts) {
                if (sz > mx) {
                    mx = sz;
                    mxcnt = 0;
                }
                if (mx == sz) mxcnt++;
            }
    
            return mxcnt;
        }
    
        int ds(int& i) {
            string num = to_string(i);
            int s = 0;
            for (char& d : num) {
                s += d-'0';
            }
    
            return s;
        }
    };