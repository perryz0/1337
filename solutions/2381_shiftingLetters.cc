// Jan. 4th, 2025 (daily)

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> prefixCache(s.length()+1, 0);

        for (auto& shift : shifts) {
            int left = shift[0];
            int right = shift[1]+1;

            if (shift[2] == 1) {
                prefixCache[right] += 1;
                prefixCache[left] -= 1;
            } 
            if (shift[2] == 0) {
                prefixCache[right] -= 1;
                prefixCache[left] += 1;
            }

            prefixCache[right] = (prefixCache[right] + 26) % 26;
            prefixCache[left] = (prefixCache[left] + 26) % 26;

        }

        int diff = 0;
        string res(s.length(), ' ');

        for (int i = prefixCache.size()-1; i > 0; --i) {
            diff += prefixCache[i] % 26;
            res[i-1] = static_cast<char>(((s[i-1]-'a' + diff) % 26) + 'a');
        }

        return res;
    }
};