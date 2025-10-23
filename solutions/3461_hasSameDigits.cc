// Oct. 22nd, 2025

class Solution {
public:
    bool hasSameDigits(string s) {
        deque<char> dq(s.begin(), s.end());
        while (dq.size()>2) {
            deque<char> tmp;
            int prev=dq.front()-'0';
            dq.pop_front();
            while (!dq.empty()) {
                tmp.push_back((prev+dq.front()-'0')%10);
                prev=dq.front()-'0';
                dq.pop_front();
            }
            dq=tmp;
        }
        return dq.front() == dq.back();
    }
};