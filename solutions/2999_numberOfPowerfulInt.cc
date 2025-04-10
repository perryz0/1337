// Apr. 9th, 2025 (daily)
// had to walkthru this one... math skill issueeee

#define ll long long

class Solution {
// private:
//     ll cnt;

private:
    string str;
    int lim;
    // int START;

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        // cnt = 0;
        str = s;
        lim = limit;
        // START=start;

        // return cnt;
        return calc(to_string(finish)) - calc(to_string(start-1));
    }

    ll calc(string f) {
        int difflen = f.length() - str.length();
        if (difflen < 0) {
            return 0;
        }

        if (difflen == 0) return (f<str) ? 0 : 1;

        ll cnt = 0;
        string suffix = f.substr(difflen);

        for (int i = 0; i<difflen; ++i) {
            if (f[i]-'0' > lim) {
                cnt += pow((lim + 1), (difflen-i));
                return cnt;
            }

            cnt += (f[i]-'0') * pow((lim+1), difflen-i-1);
        }

        return (suffix >= str) ? cnt+1 : cnt;
    }
};