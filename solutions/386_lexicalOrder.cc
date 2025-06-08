// June 7th, 2025 (daily)

class Solution {
private:
    int num;
    vector<int> ans;

    void dfs(int curr) {
        if (curr > num) return;

        ans.push_back(curr);

        for (int i=0; i<=9; ++i) {
            int next = curr * 10 + i;

            if (next > num) return;

            dfs(next);
        }
    }

public:
    vector<int> lexicalOrder(int n) {
        // vector<int> res;
        num=n;
        
        for (int i=1; i<=9; ++i) {
            // int num=i;
            // if (num > n) continue;
            // res.push_back(num);
            // int end=num+1;
            
            // while (num < n) {
            //     num*=10;
            //     end*=10;
            // }
            // for (int j=num/10; j<end/10; ++j) {
            //     if (j > n) {
            //         j
            //     } else {
            //         res.push_back(j);
            //     }
            // }


            // rec dfs
            dfs(i);
        }

        return ans;
    }
};