// Jan. 11th, 2025 (daily)

class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.length() % 2 == 1) return false;

        stack<int> strictLeft;
        stack<int> unlocked;
        for (int i = 0; i < s.length(); ++i) {

            if (locked[i] == '0') unlocked.push(i);

            else if (s[i] == '(') strictLeft.push(i);

            else {
                if (!strictLeft.empty()) strictLeft.pop();
                else if (!unlocked.empty()) unlocked.pop();
                else return false;
            }

        }

        if (strictLeft.size() > unlocked.size()) return false;

        while (!strictLeft.empty() && !unlocked.empty()) {
            if (unlocked.top() < strictLeft.top())return false;
            unlocked.pop();
            strictLeft.pop();
        }

        if (unlocked.size() % 2 == 1) return false;

        return true; 
    }
};