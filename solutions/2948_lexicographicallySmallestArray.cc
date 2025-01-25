// Jan. 24th, 2025 (daily)

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        unordered_map<int, vector<int>> idxMap;
        for (int i = 0; i < nums.size(); ++i) idxMap[nums[i]].push_back(i);

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        vector<vector<int>> connectedComps;
        int curr = sorted[0];
        vector<int> currComp;
        for (int& num : sorted) {
            if (abs(curr - num) <= limit) currComp.push_back(num);
            else { connectedComps.push_back(currComp); currComp = {num}; }
            curr = num;
        }
        // currComp has the last remaining component
        if (!currComp.empty()) connectedComps.push_back(currComp);

        vector<int> res(nums.size());

        for (vector<int>& comp : connectedComps) {
            vector<int> currIdxs(comp.size());
            for (int i = 0; i < comp.size(); ++i) {
                currIdxs[i] = idxMap[comp[i]][idxMap[comp[i]].size()-1];
                idxMap[comp[i]].pop_back();
            }
            sort(currIdxs.begin(), currIdxs.end());

            for (int i = 0; i < comp.size(); ++i) res[currIdxs[i]] = comp[i];
        }

        return res;
    }
};


        // unordered_map<int, int> numCnts;

        // for (int i = 0; i < nums.size(); ++i) numCnts[nums[i]]++;

        // vector<pair<pair<int,int>,vector<pair<int, int>>>> connectedComps; // {{min, max}, [{num1: idx}, {num2: idx}, {num3: idx}...]}

        // vector<pair<pair<int,int>,vector<int>>> connectedComps; // {{min, max}, [num1, num2, num3...]}