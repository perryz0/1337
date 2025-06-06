// June 5th, 2025 (daily)

class Solution {
public:
    string robotWithString(string s) {
        string ans;
        int n=s.length();
        int l=0;
        int r=0;
        vector<bool> vis(n,0);
        // queue<char> commited;
        stack<char> rev;

        for (int i=0; i<26; ++i) {
            // bool found=false;
            char target = 'a'+i;
            // stack<char> stk;
            for (int j=r; j<n; ++j) {
                if (s[j] == target) {
                    // first check the top of the commited stack to see if its lex smaller
                    while (!rev.empty() && rev.top() <= target) {
                        ans.push_back(rev.top());
                        rev.pop();
                    }
                    ans.push_back(s[j]);
                    vis[j]=true;
                    while (l<j) {
                        if (!vis[l]) rev.push(s[l]);
                        l++;
                        // stk.pop();
                        // cout << "stack contains: " << commited.front() << " ";
                    }
                    // cout << endl;
                    r=j+1;
                    // cout << "iter " << i << endl;
                }
                // else {
                //     rev.push(s[j]);
                // }
            }
            if (ans.length() == n) break;
        }

        while (!rev.empty()) {
            ans.push_back(rev.top());
            rev.pop();
            // cout << ans << endl;
        }


        return ans;
    }
};

















// class Solution {
// public:
//     string robotWithString(string s) {
//         string ans;
//         int n=s.length();
//         int l=0;
//         queue<char> commited;

//         for (int i=0; i<26; ++i) {
//             // bool found=false;
//             char target = 'a'+i;
//             stack<char> stk;
//             for (int j=l; j<n; ++j) {
//                 if (s[j] == target) {
//                     // first check the top of the commited stack to see if its lex smaller
//                     while (!commited.empty() && commited.front() <= target) {
//                         ans.push_back(commited.front());
//                         commited.pop();
//                     }
//                     ans.push_back(s[j]);
//                     while (!stk.empty()) {
//                         commited.push(stk.top());
//                         stk.pop();
//                         // cout << "stack contains: " << commited.front() << " ";
//                     }
//                     // cout << endl;
//                     l=j+1;
//                     // cout << "iter " << i << endl;
//                 }
//                 else {
//                     stk.push(s[j]);
//                 }
//             }
//             if (ans.length() == n) break;
//         }

//         while (!commited.empty()) {
//             ans.push_back(commited.front());
//             commited.pop();
//             // cout << ans << endl;
//         }


//         return ans;
//     }
// };