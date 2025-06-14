// June 13th, 2025 (daily)

class Solution {
public:
    int minMaxDifference(int num) {
        string n=to_string(num);
        char toReplace=9;
        for (char& c : n) {
            if (c != '9') {
                toReplace = c;
                break;
            }
        }

        // cout << toReplace << endl;

        int mn=0, mx=0;
        for (int i=0; i<n.length(); i++) {
            // int mn_digit = (n[i] == toReplace) ? 0 : n[i]-'0';
            int mx_digit = (n[i] == toReplace) ? 9 : n[i]-'0';
            // cout << mn_digit << "," << mx_digit << endl;
            // mn += (pow(10,n.length()-1-i) * mn_digit);
            mx += (pow(10,n.length()-1-i) * mx_digit);
        }

        // min always created by replacing MSB
        for (int i=0; i<n.length(); i++) {
            int mn_digit = (n[i] == n[0]) ? 0 : n[i]-'0';
            // int mx_digit = (n[i] == toReplace) ? 9 : n[i]-'0';
            // cout << mn_digit << "," << mx_digit << endl;
            mn += (pow(10,n.length()-1-i) * mn_digit);
            // mx += (pow(10,n.length()-1-i) * mx_digit);
        }

        // cout << mx << "," << mn << endl;

        return mx-mn;
    }
};