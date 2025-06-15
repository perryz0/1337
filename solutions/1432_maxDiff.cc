// June 14th, 2025 (daily)

class Solution {
public:
    int maxDiff(int num) {
        // max is always 9 leading
        // min is leading 1's until first non-1

        int mn_digit = 1, mn_rep = -1;
        string n = to_string(num);
        for (int i=0; i<n.length(); ++i) {
            if (n[i] != '0' && n[i] != '1') {
                mn_rep=n[i]-'0';
                if (i != 0) mn_digit = 0;
                break;
            }
        }

        int mn=num;
        if (mn_rep != -1) {
            mn=0;
            for (int i=0; i<n.length(); ++i) {
                int d = (mn_rep == n[i]-'0') ? mn_digit : n[i]-'0';
                mn += pow(10,(n.length()-1-i))*d;
            }
        }

        int mx_digit=9, mx_rep=-1;
        for (int i=0; i<n.length(); ++i) {
            if (n[i] != '9') {
                mx_rep=n[i]-'0';
                break;
            }
        }

        int mx=num;
        if (mx_rep != -1) {
            mx=0;
            for (int i=0; i<n.length(); ++i) {
                int d = (mx_rep == n[i]-'0') ? mx_digit : n[i]-'0';
                mx += pow(10,(n.length()-1-i))*d;
            }
        }

        // cout << mx_rep << "," << mn_rep << endl;

        // cout << mx << "," << mn << endl;
        
        return mx-mn;
    }
};