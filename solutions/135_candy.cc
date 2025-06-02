// June 1st, 2025 (daily)

class Solution {
public:
    int candy(vector<int>& ratings) {
        // each person has at least one candy
        int n=ratings.size();
        // int ans=n;

        vector<int> candies(n, 1);

        // if (ratings[0] != ratings[1]) ans++;
        // int prev=ratings[1];

        // now greedily add such that the neighbors will work properly
        //FIRST PASS (L2R)
        for (int i=1; i<n; ++i) {
            if (ratings[i] > ratings[i-1]) candies[i] = candies[i-1]+1;
        }

        //SECOND PASS (R2L)
        for (int i=n-2; i>=0; --i) {
            if (ratings[i] > ratings[i+1]) candies[i] = max(candies[i], candies[i+1]+1);
        }

        //FINAL PASS (sum)
        int ans=0;
        for (const int& c : candies) ans+=c;

        // int running=0;
        // int prev=running;
        // for (int i=1; i<n-1; ++i) {
        //     if (ratings[i] > ratings[i-1]) {
        //         ans += (++running);
        //     }
        //     if (ratings[i+1] > ratings[i]) {
        //         ans += (++running);
        //     }
        
        //     prev=running;
        // }

        return ans;
    }
};


            // else dont do anything because it just needs 1
            // else {
            //     ans += (running == 0) ? 0 : --running;
            // }