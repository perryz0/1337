// Feb. 7th, 2025 (daily)

class NumberContainers {
    private:
        unordered_map<int, set<int>> container; // {currNumber : indices}
        unordered_map<int, int> indexMap;   // {idx : currNumber}
    
    public:
        NumberContainers() = default;
        
        void change(int index, int number) {
            // if already index already taken, must remove prev number from pq
            auto imIter = indexMap.find(index);
            if (imIter != indexMap.end()) {
                container.find(imIter->second)->second.erase(index);
            }
            indexMap[index] = number;
            container[number].insert(index);
        }
        
        int find(int number) {
            auto iter = container.find(number);
            if (iter != container.end()) {
                if (!iter->second.empty()) return *iter->second.begin();
            }
            return -1;
        }
    };
    
    /**
     * Your NumberContainers object will be instantiated and called as such:
     * NumberContainers* obj = new NumberContainers();
     * obj->change(index,number);
     * int param_2 = obj->find(number);
     */