// July 5th, 2025

class FindSumPairs {
private:
    vector<int> _n2;
    unordered_map<int,int> _n2freqs;
    map<int,int> _n1freqs;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : _n2(nums2) {
        for (const int& n : nums1) _n1freqs[n]++;
        for (const int& n : _n2) _n2freqs[n]++;
    }
    
    void add(int index, int val) {
        _n2freqs[_n2[index]]--;
        _n2[index] += val;
        _n2freqs[_n2[index]]++;
    }
    
    int count(int tot) {
        int ans=0;

        for (auto [val, f1] : _n1freqs) {
            if (val >= tot) break;
            ans += (f1 * _n2freqs[tot-val]);
        }

        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */