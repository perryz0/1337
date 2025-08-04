// Aug 3rd, 2025

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // sliding window with two buckets
        // gotta also keep track of last_index of the first fruit

        unordered_map<int,int> cnts; // fruit_id, freq
        unordered_map<int,int> lastIndex;
        int n=fruits.size();
        int ans=0;
        for (int i=0; i<n; ++i) {
            if (!cnts.contains(fruits[i]) && cnts.size() == 2) {
                // if (cnts.size() == 2) {
                int prev = fruits[i-1];
                // int prevCnt = cnts[prev];
                cnts = unordered_map<int,int>();
                int lastToDelete = INT_MAX;
                for (auto [k,v] : lastIndex) lastToDelete=min(lastToDelete, v); 
                lastIndex = unordered_map<int,int>();
                lastIndex[prev]=i-1;
                cnts[prev]=i-lastToDelete-1;
                

                // } else {

                // }
            }

            // always add and update lastIndex
            lastIndex[fruits[i]]=i;
            cnts[fruits[i]]++;

            // always update
            int curr=0;
            for (auto [k,v] : cnts) {
                // cout << "fruit: " << k << ", cnt: " << v << endl;
                curr+=v;
            }
            // cout << "--------" << endl;
            ans=max(ans,curr);
        }

        return ans;
    }
};