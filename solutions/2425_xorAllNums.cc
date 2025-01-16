// Jan. 15th, 2025 (daily)

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

        int res = 0;
        if (nums2.size()%2 == 1) for (int& num : nums1) res ^= num;
        if (nums1.size()%2 == 1) for (int& num : nums2) res ^= num;

        return res;
    }
};



        // unordered_map<int, int> xorCnts;

        // for (int& num : nums1) xorCnts[num] = (xorCnts[num] + nums2.size())%2;
        // for (int& num : nums2) xorCnts[num] = (xorCnts[num] + nums1.size())%2;

        // int res = 0;
        // for (auto& xorCnt : xorCnts) if (xorCnt.second == 1) res ^= xorCnt.first;

        // return res;