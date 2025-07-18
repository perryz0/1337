// July 17th, 2025

// editorial, cheat day...

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n3 = nums.size(), n = n3 / 3;
        vector<long long> part1(n + 1);
        long long sum = 0;
        // max heap
        priority_queue<int> ql;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            ql.push(nums[i]);
        }
        part1[0] = sum;
        for (int i = n; i < n * 2; ++i) {
            sum += nums[i];
            ql.push(nums[i]);
            sum -= ql.top();
            ql.pop();
            part1[i - (n - 1)] = sum;
        }

        long long part2 = 0;
        // min heap
        priority_queue<int, vector<int>, greater<int>> qr;
        for (int i = n * 3 - 1; i >= n * 2; --i) {
            part2 += nums[i];
            qr.push(nums[i]);
        }
        long long ans = part1[n] - part2;
        for (int i = n * 2 - 1; i >= n; --i) {
            part2 += nums[i];
            qr.push(nums[i]);
            part2 -= qr.top();
            qr.pop();
            ans = min(ans, part1[i - n] - part2);
        }
        return ans;
    }
};










// using ll = long long;

// class Solution {
// public:
//     long long minimumDifference(vector<int>& nums) {
//         // [first n-sized subarray][second n-sized subarray]
//         // have to minimize the first subarray sum, and maximize the second subarray sum
//         // two heaps? one minHeap, one maxHeap
//         // nlogn removes, which is 1e5*log(1e5), OK
//         // maxpq.top vs. minpq.top?
//         // there might be intermediate states where subarray values are not 'committed' to either first/second subarray
//         // so only n/3 loop iterations?

//         priority_queue<pair<int,int>> maxpq;    // current values, only first half of the subarray
//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minpq;  // second half; <value, index>
//         for (int i=0; i<nums.size()/2; ++i) maxpq.push({nums[i],i});
//         for (int i=nums.size()/2; i<nums.size(); ++i) minpq.push({nums[i],i});

//         unordered_set<int> toExclude;
//         int n = nums.size()/3;  // assume the len must be a multiple of 3

//         // preprocess n=1,n=2 cases
//         if (n<=2) {
//             // brute force
//             int ans=INT_MAX;
//             if (n==1) {
//                 for (int i=0; i<n*3; ++i) { // to skip
//                     int curr=0;
//                     for (int j=0; j<n*3; ++j) {
//                         if (i==j) continue;
//                         if (curr == 0) curr+=nums[j];
//                         else curr -= nums[j];
//                     }
//                     ans=min(ans, curr);
//                 }
//                 return ans;
//             }
//             if (n==2) {
//                 for (int i=0; i<n*3; ++i) { // to skip
//                     for (int j=0; j<n*3; ++j) { // to skip
//                         int curr=0;
//                         int cnt=0;
//                         if (i==j) continue;
//                         for (int k=0; k<n*3; ++k) {
//                             if (k==i || k==j) continue;
//                             if (cnt < n) curr+=nums[k];
//                             else curr -= nums[k];
//                             ++cnt;
//                         }
//                         // cout << "{" << i << "," << j << "}: " << curr << endl;
//                         ans=min(ans, curr);
//                     }
//                 }
//                 return ans;
//             }
//         }

//         // now all cases are n>=3, so we can rm in batches of three

//         // greedy heap removes + modification of top
//         // int iters=ceil((double(n)/3));
//         for (int i=0; i<n/3; ++i) {
//             // remove in batches of triples, to guarantee subarray balance so no intermediate states?
//             for (int j=0; j<3; ++j) {

//             }
//         }


//         // construct the final subarray
//         ll first=0;
//         int it=0;
//         for (; it<2*n; ++it) {
//             if (toExclude.contains(it)) continue;
//             first += nums[it];
//         }
//         ll second=0;
//         for (; it<nums.size(); ++it) {
//             if (toExclude.contains(it)) continue;
//             second += nums[it];
//         }

//         return first-second;
//     }
// };