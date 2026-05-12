class Solution {
private:
    vector<vector<int>> factors;

    void PRINT(const vector<int>& V){
        cout << "[";
        for(const int& v : V) cout << " " << v;
        cout << " ]" << endl;
    }

    vector<int> findFactors(int num){
        if(num==1) return {1};
        vector<int> f={1,num};
        for(int i=2; i*i<=num; ++i){
            if(num%i == 0) {
                f.push_back(i);
                if(num/i != i) f.push_back(num/i);
            }
        }

        sort(f.begin(),f.end());

        // cout << "factors for num=" << num << ": ";
        // PRINT(f);

        return f;
    }
    
public:
    long long minArraySum(vector<int>& nums) {
        // for every num, find the factors
        // greedily check if the smallest factors exist, if so, break and add that to the sum
        unordered_set<int> s;
        for(const int& num : nums){
            factors.push_back(findFactors(num));
            s.insert(num);
        }

        long long ans=0;
        for(const auto& V : factors){
            for(const int& f : V){
                if(s.contains(f)){
                    ans += f;
                    break;
                }
            }
        }

        return ans;
    }
};