// Jan. 2nd, 2025 (daily)

class Solution {
public:
    string reorganizeString(string s) {
        string res = "";
        priority_queue<pair<int, char>> pq;

        vector<int> freqs(26, 0);

        for (int i = 0; i < s.length(); ++i) freqs[s[i]-'a']++;

        for (int i = 0; i < freqs.size(); ++i) {
            if (freqs[i] != 0) pq.push({freqs[i], i+'a'});
        }

        pair<int, char> prevLetter = pq.top();
        char prev = prevLetter.second;
        pq.pop();
        res += prev;
        if (prevLetter.first != 1) pq.push({prevLetter.first-1, prev});

        while (!pq.empty()) {
            pair<int, char> currLetter = pq.top();
            char curr = currLetter.second;
            pq.pop();

            if (curr != prev) {
                res += curr;
                if (currLetter.first != 1) pq.push({currLetter.first-1, curr});
                prev = curr;
            } else {
                if (!pq.empty()) {
                    pair<int, char> nextInLine = pq.top();
                    char actualCurr = nextInLine.second;
                    pq.pop();
                    res += actualCurr;
                    pq.push({currLetter.first, curr});
                    if (nextInLine.first != 1) pq.push({nextInLine.first-1, actualCurr});
                    prev = actualCurr;
                } else {
                    return "";
                }
            }

        }

        return res;
    }
};