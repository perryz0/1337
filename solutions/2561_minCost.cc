// Aug 1st, 2025

using ll = long long;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> f1, f2;
        for (const int& v : basket1) f1[v]++;
        for (const int& v : basket2) f2[v]++;

        // check impossibility
        int gmin=INT_MAX;
        for (const auto [v,f] : f1) {
            gmin=min(gmin,v);
            if ((f+f2[v])%2) return -1;
        }
        for (const auto [v,f] : f2) {
            gmin=min(gmin,v);
            if ((f+f1[v])%2) return -1;
        }

        // find the swap elements
        // unordered_set<int> sw_set;
        // for (const auto [v,f] : f1) if (f2[v] != f) sw_set.insert(v);
        // for (const auto [v,f] : f2) if (f1[v] != f) sw_set.insert(v);
        // vector<int> sw(sw_set.begin(), sw_set.end());
        vector<int> sw;
        // should deduplicate, the signed comparison
        for (const auto [v,f] : f1) if (f2[v] < f) for (int i=0;i<(max(f2[v],f)-min(f2[v],f))/2;++i) sw.push_back(v);
        for (const auto [v,f] : f2) if (f1[v] < f) for (int i=0;i<(max(f1[v],f)-min(f1[v],f))/2;++i) sw.push_back(v);
        sort(sw.begin(),sw.end());

        // two pointers to minimize totalCost
        ll ans=0;
        int l=0, r=sw.size()-1;
        while (l<r) {
            ans+=min(sw[l], 2*gmin);     // reusing elements for swap, using globalMin
            l++;
            r--;
        }

        return ans;
    }
};