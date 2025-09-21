// Sep. 19th, 2025

class Router {
private:
    // Store as {timestamp, source} so each deque is sorted by timestamp
    unordered_map<int, deque<pair<int,int>>> dt; 
    unordered_map<int, unordered_map<int, unordered_set<int>>> mp;  
    deque<int> dstFinder;
    int CAP;

public:
    Router(int memoryLimit) {
        CAP = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if (mp[source][destination].contains(timestamp)) return false;
        if ((int)dstFinder.size() == CAP) {
            int dst = dstFinder.front();
            dstFinder.pop_front();
            auto [ts, src] = dt[dst].front();   // note: {timestamp, source}
            dt[dst].pop_front();
            mp[src][dst].erase(ts);
        }

        dstFinder.push_back(destination);
        mp[source][destination].insert(timestamp);
        dt[destination].push_back({timestamp, source});
        return true;
    }
    
    vector<int> forwardPacket() {
        if (dstFinder.empty()) return {}; // no packets
        
        int dst = dstFinder.front();
        dstFinder.pop_front();
        auto [ts, src] = dt[dst].front(); // {timestamp, source}
        dt[dst].pop_front();
        mp[src][dst].erase(ts);
        return {src, dst, ts};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto &dq = dt[destination];

        auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.first < b.first; // compare timestamp only
        };

        auto it1 = lower_bound(dq.begin(), dq.end(), make_pair(startTime, 0), cmp);
        auto it2 = upper_bound(dq.begin(), dq.end(), make_pair(endTime, INT_MAX), cmp);

        return it2 - it1;
    }
};