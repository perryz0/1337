// Oct. 15th, 2025

class Solution {
private:
    void PRINT(const vector<int>& V) {
        cout << "[";
        for (const int& v : V) cout << v << " ";
        cout << "]" << endl;
    }

public:
    int findSmallestInteger(vector<int>& nums, int value) {
        // modulo buckets
        // ans is the (min(bucket[i])+1)*value
        vector<int> mod(value, 0);

        // first normalize all nums so nothing is negative
        int norm=nums[0];
        for (const int& num : nums) norm=min(norm, num);
        
        // norm must be multiple of value
        // normalize, then throw them into the buckets
        if (norm < 0) {
            norm *= -1;
            if (norm%value) norm += (value-(norm%value));
        }
        else {
            norm=0;
        }
        for (int& num : nums) {
            int normalized = ((long)(num+norm))%value;
            // cout << normalized << endl;
            mod[normalized]++;
        }

        // PRINT(mod);

        int idx=0, minFreq=INT_MAX;
        for (int i=0; i<value; ++i) {
            if (minFreq > mod[i]) {
                minFreq=mod[i];
                idx=i;
            }
        }

        if (idx==0) idx=value;  // normalize to the base.

        int ans = (minFreq)*value;

        // cout << "smallest bucket: " << idx << ", freq: " << minFreq << endl;

        if (idx!=value) ans += idx;

        return ans;
    }
};