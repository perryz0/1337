// May 11th, 2025 (daily)

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        // better soln, check all possible
        // unordered_map<int,int> freqs;
        int freqs[10] = {};
        for (int& d : digits) freqs[d]++;
        int n = digits.size();

        vector<int> res;
        for (int i=100; i<=999; ++i) {
            if (i%2) continue;
            string curr = to_string(i);
            int tmp[10];
            memcpy(tmp, freqs, sizeof(freqs));
            // unordered_map<int,int> tmp = freqs;
            for (int j=0; j<3; ++j) {
                if (tmp[curr[j]-'0'] == 0) break;
                tmp[curr[j]-'0']--;
                if (j==2) res.push_back(i);
            }
            // unordered_map<int,int> tmp = freqs;
            // for (char& c : curr) tmp[c-'0']--;
            // int valid = 0;
            // for (const auto& [d,f] : tmp) {
            //     if (f >= 0) valid++;
            // }
            // if (valid == n) res.push_back(i);
        }

        return res;
    }
};




        // explicit creation
        // // set<int> s;
        // // for (int& d : digits) s.insert(d);

        // // vector<int> d2;
        // // for (const int& d : s) d2.push_back(d);
        // sort(digits.begin(), digits.end());
        // int n = digits.size();

        // set<int> res;
        // for (int i=0; i<n; ++i) {
        //     if (digits[i] == 0) continue;
        //     // string num = to_string(digits[i]);
        //     int num = digits[i]*10;
        //     for (int j=0; j<n; ++j) {
        //         // num.push_back(digits[j]);
        //         // num *= 10;
        //         if (j == i) continue;
        //         num += digits[j];
        //         for (int k=0; k<n; ++k) {
        //             if (digits[k] % 2 == 1 || k == i || k == j) continue;
        //             res.insert((num*10 + digits[k]));
        //         }
        //         num -= digits[j];
        //     }
        // }

        // vector<int> vecres;
        // for (const int& v : res) vecres.push_back(v);

        // return vecres;