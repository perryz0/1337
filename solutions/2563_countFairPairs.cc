// Apr. 18th, 2025 (daily)

#define ll long long

class Solution {
private:
    vector<int> vec;

public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        vec = nums;
        sort(vec.begin(), vec.end());
        int n = vec.size();
        ll cnt = 0;
        
        for (int i = n - 1; i > 0; --i) {
            if (vec[i] + vec[0] > upper) continue;
            if (vec[i] + vec[i - 1] < lower) break;
            
            int left = findLow(i, lower);
            int right = findUp(i, upper);
            
            if (left <= right)
                cnt += (right - left + 1);
        }
        
        return cnt;
    }
    
    int findLow(int i, int target) {
        int l = 0, r = i - 1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (vec[mid] + vec[i] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        
        return l;
    }
    
    int findUp(int i, int target) {
        int l = 0, r = i - 1;
        
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (vec[mid] + vec[i] <= target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        
        return r;
    }
};




        // for (int& num : nums) cout << num << endl;

        // int l = 0, r = 0;

        // for (int i = 0; i<n; ++i) {
        //     if ((ll)nums[i] + (ll)nums[n - 1] < lower) continue;
        //     if ((ll)nums[i] + (ll)nums[i + 1 >= n ? n - 1 : i + 1] > upper) break;
        //     while (r < n && (ll)nums[i] + (ll)nums[r] <= upper) r++;
        //     while (l < r && (ll)nums[i] + (ll)nums[l] < lower) l++;
        //     // ll range = (ll)(r - l);
        //     // if (i > l && i <= r) range--;

        //     cnt += (i >= l && i<r) ? (r-l-1) : (r-l);
        // }

        // while (l<r) {
        //     if ((ll)nums[l] + (ll)nums[r] < lower) {
        //         l++;
        //         continue;
        //     }
        //     while ((ll)nums[l] + (ll)nums[r] > upper) {
        //         r--;
        //     }
        //     cnt += (r-l+1);
        // }

        // return cnt/2;