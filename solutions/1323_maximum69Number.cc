// Aug 15th, 2025

class Solution {
public:
    int maximum69Number (int num) {
        string n=to_string(num);
        int change=-1;
        for (int i=0; i<n.length(); ++i) {
            if (n[i] == '6') {
                change = i;
                break;
            }
        }

        if (change != -1) n[change]='9';
        
        return (change == -1) ? num : stoi(n);
    }
};