// Apr. 19th, 2025 (daily)

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        // whichever answers[i] that does not have answers+1 cnt, should be added +1 to the tot
        int res = 0;
        unordered_map<int,int> cnts;

        for (int& ans : answers) {
            cnts[ans]++;
        }

        for (auto& [num, cnt] : cnts) {
            res += (ceil((double)cnt/(double)(num+1))) * (num+1);
        }

        return res;
    }
};