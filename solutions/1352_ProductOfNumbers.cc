// Feb. 13th, 2025 (daily)

#define ll long long

class ProductOfNumbers {
private:
    vector<ll> kProds;

public:
    ProductOfNumbers() {}
    
    void add(int num) {
        if (kProds.empty()) { kProds.push_back(num); return; }
        if (num == 0) { kProds.clear(); kProds.push_back(0); return; }

        ll prev = kProds[kProds.size()-1];
        kProds.push_back((ll)((prev == 0) ? num : prev * num));
    }
    
    int getProduct(int k) {
        if (kProds.size() == 1) return kProds[0];
        ll last = kProds[kProds.size()-1];

        if (k > kProds.size() || k == kProds.size() && kProds[0] == 0) return 0;

        ll kthMinusOne;
        if (k == kProds.size()) kthMinusOne = 1;
        else kthMinusOne = kProds[kProds.size()-k-1];

        return (kthMinusOne == 0) ? last : static_cast<int>(last/kthMinusOne);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */