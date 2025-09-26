// Sep. 23rd, 2025

using ll = long long;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        double quo=(double)numerator/denominator;
        if (quo == (ll)numerator/(ll)denominator) return to_string((ll)numerator/(ll)denominator); // covers the 0 and the whole div case
        
        string ans;

        // handle sign
        if ((numerator < 0) ^ (denominator < 0)) ans.push_back('-');

        // convert to positive long long to avoid overflow
        ll n = llabs((ll)numerator);
        ll d = llabs((ll)denominator);

        // integer part
        ans += to_string(n / d);
        ll rem = n % d;
        if (rem == 0) return ans; // no frac part

        ans.push_back('.');

        // map: rem -> index in ans where this remainder first appeared
        unordered_map<ll, int> seen;

        while (rem != 0) {
            if (seen.count(rem)) {
                // insert '(' for the start of the repaet
                ans.insert(seen[rem], "(");
                ans.push_back(')');
                break;
            }

            seen[rem] = ans.size();
            rem *= 10;
            ans.push_back('0' + rem / d);
            rem %= d;
        }

        return ans;
    }
};



        // string deci=ans.substr(ans.find('.')+1);

        // // strip zeroes
        // for (int i=deci.length()-1; i>=0; --i) if (deci[i] == '0') deci.pop_back();
        // cout << deci << endl;

        // // scan repeating
        // for (int i=0; i<deci.length(); ++i) { //starting
        //     for (int j)
        // }


        // cout << deci << endl;
        // // if (deci.length()>3) {
        // //     deci = '(' + deci.substr(0,3) + ')';
        // // }
        // ans = ans.substr(0, ans.find('.')+1) + deci;