// Apr. 10th, 2025 (daily)

class Solution {
    // private:
        // int cnt;
    
    public:
        int countSymmetricIntegers(int low, int high) {
            int cnt = 0;
    
            for (int i = low; i<=high; ++i) {
                cnt += check(i);
            }
    
            return cnt;
        }
    
        bool check(int num) {
            string n = to_string(num);
            if (n.length()%2) return false;
            int l = 0, r = n.length()-1;
            int lsz = 0, rsz = 0;
    
            while (l<r) {
                lsz += n[l];
                rsz += n[r];
                l++;
                r--;
            }
    
            // if (lsz != rsz) return false;
    
            // cout << num << " " << endl;
            return (lsz != rsz) ? false : true;
        }
    };