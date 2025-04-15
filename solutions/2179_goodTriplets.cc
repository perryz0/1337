// Apr. 13th, 2025 (daily)
// coming back for fenwick later... works tho

#define ll long long

class Solution {
// private:
    // ll cnt;

public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        ll cnt = 0;
        int n = nums1.size();

        vector<int> n2pos(n);
        for (int i = 0; i < n; ++i) n2pos[nums2[i]] = i;

        vector<int> mapped(n);
        for (int i = 0; i < n; ++i)
            mapped[i] = n2pos[nums1[i]];

        vector<int> rs(mapped.begin(), mapped.end());
        sort(rs.begin(), rs.end());

        vector<int> ls;

        for (int j = 0; j < n; ++j) {
            int v = mapped[j];
            auto it_r = lower_bound(rs.begin(), rs.end(), v);
            rs.erase(it_r);  // o(n) worst case, but amortized better

            int left_smaller = lower_bound(ls.begin(), ls.end(), v)-ls.begin();
            int right_larger = rs.end()-upper_bound(rs.begin(), rs.end(), v);

            cnt += (ll)left_smaller * right_larger;

            ls.insert(upper_bound(ls.begin(), ls.end(), v), v);
        }

        return cnt;
    }
};