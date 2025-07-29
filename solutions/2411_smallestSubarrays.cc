// July 28th, 2025
// kinda cool bit strategy

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> pos(31,-1);
        vector<int> ans(n);
        for (int i=n-1; i>=0; --i) {
            for (int bit=0; bit<31; ++bit) {
                if (nums[i]&(1<<bit)) {
                    pos[bit]=i;
                }
            }
            int furthest=i;
            for (int bit=0; bit<31; ++bit) {
                if (pos[bit]!=-1) {
                    furthest=max(furthest,pos[bit]);
                }
            }
            ans[i]=furthest-i+1;
        }
        return ans;
    }
};








// class Solution {
// private:
//     int n;
//     vector<int> MAXORS;
//     vector<int> numbers;
//     vector<int> ans;

//     // 'used' i.e. used indices (not subseq)
//     void backtrack(int start, int curr, int idx, unordered_set<int> used) {
//         if (curr == MAXORS[start]) {
//             ans[start] = min(ans[start], (int)used.size());
//         }

//         for (int i=idx+1; i<n; ++i) {
//             int newCurr = curr | numbers[i];
//             used.insert(i);
//             backtrack(start, newCurr, i, used);
//             used.erase(i);
//         }
//     }

//     void PRINTER(const vector<int>& v) {
//         cout << "[";
//         for (const int& val : v) cout << val << " ";
//         cout << "]\n";
//     }

// public:
//     vector<int> smallestSubarrays(vector<int>& nums) {
//         // first find all the maxORs for each subarray starting at index i
//         n=nums.size();
//         MAXORS=vector<int>(n,0);
//         numbers=nums;
//         MAXORS[n-1] = nums[n-1];
//         for (int i=n-2; i>=0; --i) MAXORS[i] = MAXORS[i+1] | nums[i];
//         PRINTER(MAXORS);

//         // // NOT choose or not choose because subarray
//         // ans=vector<int>(n,INT_MAX);
//         // for (int i=0; i<n; ++i) {
//         //     backtrack(i, nums[i], i, {i});
//         // }

//         ans=vector<int>(n,1);   // ans[n-1] MUST BE 1
//         int running=0;
//         for (int i=0; i<n-1; ++i) {
//             int withoutCurr = nums[i+1];
//             while ((withoutCurr | nums[i]) < MAXORS[i]) {

//             }
//         }


//         return ans;
//     }
// };




//             // cout << "[";
//             // for (int i : used) cout << i << " ";
//             // cout << "]\n";