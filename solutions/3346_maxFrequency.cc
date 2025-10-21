// Oct. 20th, 2025

class Solution {
private:
    void PRINT(const vector<int>& V) {
        cout << "[";
        for (const int& v : V) cout << v << " ";
        cout << "]" << endl;
    }

public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        // normalize to negative
        // prefix sum on the range
        // [nums[i]-k...nums[i]+k] +1, then nums[i]+k+1 would -1
        // 3*10e5 max elems in the alloc
        // numOperations is trivial, unrelated to the scan itself
        int n=nums.size();
        for (int i=0; i<n; ++i) nums[i]-=1e5;

        // PRINT(nums);

        int sz = nums[n-1]-nums[0]+2+2*k;
        vector<int> ps(sz,0);

        // cout << "size of ps: " << sz << endl;
        // PRINT(ps);

        // cout << "wtf" << endl;

        // normalize first
        int BASE=nums[0];
        for (int i=0; i<n; ++i) nums[i] += (-1)*BASE+k;   // so -k gets to the lower bound, +k gets to upper bound
        // PRINT(nums);

        for (const int& num : nums) {
            ps[num-k]++;
            ps[num+k+1]--;
        }

        // cout << "wtf" << endl;

        int maxOverlap=1;   // find max overlap
        unordered_map<int,int> F;
        for (const int& num : nums) F[num]++;

        for (int i=1; i<sz; ++i) {
            ps[i] += ps[i-1];
            int currFreq = (F.contains(i)) ? F[i] : 0;
            maxOverlap=max(maxOverlap, min(currFreq+numOperations, ps[i]));
        }

        // cout << "after:" << endl;
        // PRINT(ps);

        return maxOverlap;

        // *CANNOT JUST COMPARE AT THE END, BOUND IT DURING THE PASS
        // logically find upper bound with numOps
        // PRINT(nums);
        // unordered_map<int,int> F;
        // for (const int& num : nums) F[num]++;
        // int MAX=1;
        // for (const auto& [v, f] : F) MAX=max(MAX,f);

        // max possible manipulations
        // return (maxOverlap > MAX+numOperations) ? MAX+numOperations : maxOverlap;
    }
};