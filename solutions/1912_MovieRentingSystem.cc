using tiii = tuple<int,int,int>;

class MovieRentingSystem {
private:
// UNRENTED hashmap<k,v> = {movie: treeset<(price, shop)>}
unordered_map<int, set<pair<int,int>>> unrented;
// PRICEFINDER FROM SHOP => {shop -> movie -> price}
unordered_map<int, unordered_map<int,int>> priceFinder;
// RENTED treemap<k,v> = {price: treeset<(shop, movie)>}
map<int, set<pair<int,int>>> rented;
// set<tiii> rented;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (const auto& e : entries) {
            int s=e[0], m=e[1], p=e[2];
            unrented[m].insert({p,s});
            priceFinder[s][m]=p;
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        // int i=0;
        for (const auto& [p, s] : unrented[movie]) {
            // ++i;
            if (ans.size() == 5) return ans;
            ans.push_back(s);
        }

        return ans;
    }
    
    // remove, need to find the price for that shop's price, always fixed
    void rent(int shop, int movie) {
        int p = priceFinder[shop][movie];
        unrented[movie].erase({p,shop});
        // rented.insert({p, shop, movie});
        rented[p].insert({shop,movie});
    }
    
    // add back
    void drop(int shop, int movie) {
        int p = priceFinder[shop][movie];
        // rented.erase({p, shop,movie});
        rented[p].erase({shop,movie});
        unrented[movie].insert({p,shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;

        // int i=0;
        // for (const auto& [p,s,m] : rented) {
        //     // ++i;
        //     if (res.size()==5) return res;
        //     res.push_back({s,m});
        // }
        for (const auto& [p,shops] : rented) {
            for (const auto& [s,m] : shops) {
                if (res.size() == 5) return res;
                res.push_back({s,m});
            }
        }

        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */