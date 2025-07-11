// July 10th, 2025

using ll = long long;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<>> available;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> busy;
        vector<int> roomCnts(n, 0);

        for (int i=0; i<n; ++i) available.push(i);

        for (auto& m : meetings) {
            ll s=m[0], e=m[1];

            while (!busy.empty() && busy.top().first <= s) {
                available.push(busy.top().second);
                busy.pop();
            }

            if (!available.empty()) {
                int room = available.top();
                available.pop();
                busy.push({e, room});
                roomCnts[room]++;
            }
            else {
                auto [availTime, room] = busy.top();
                busy.pop();
                busy.push({availTime + ((ll)e-s), room});
                roomCnts[room]++;
            }
        }

        int ans = 0;
        for (int i=1; i<n; ++i)
            if (roomCnts[i] > roomCnts[ans])
                ans = i;

        return ans;
    }
};


// using tiii = tuple<int,int,int>;

// class Solution {
// public:
//     int mostBooked(int n, vector<vector<int>>& meetings) {
//         priority_queue<tiii, vector<tiii>, greater<>> available;    // startTime, roomID, available.top()
//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> queued;       // start, end; MINPQ
//         vector<int> roomCnts(n,0);
//         for (int i=0; i<n; ++i) available.push({-1,i, -1});
//         for (auto m : meetings) queued.push({m[0], m[1]});

//         priority_queue<tiii, vector<tiii>, greater<>> temp;
//         while (!queued.empty()) {
//             auto [s, e] = queued.top();
//             // cout << "start: " << s << ", end: " << e << endl;
//             queued.pop();

//             while (get<2>(available.top()) < e) {
//                 temp.push(available.top());
//                 available.pop();
//             }
//             auto [prevStart, roomID, prevEnd] = available.top();
//             available.pop();
//             roomCnts[roomID]++;
//             if (s >= prevEnd) {
//                 available.push({s, roomID, e});
//             } else {
//                 available.push({s+(s-prevEnd), roomID, e+(s-prevEnd)});
//             }
//             while (!temp.empty()) {
//                 available.push(temp.top());
//                 temp.pop();
//             }
//         }

//         int ans=0;
//         int curMax=roomCnts[0];
//         // cout << "room 0: " << roomCnts[0] << endl;
//         for (int i=1; i<n; ++i) {
//             // cout << "room " << i << ": " << roomCnts[0] << endl;
//             if (roomCnts[i] > curMax) {
//                 cout << i << endl;
//                 curMax = roomCnts[i];
//                 ans=i;
//             }
//         }

//         return ans;
//     }
// };




// MLE/TLE lol
// class Solution {
// private:
//     vector<int> bookedUntil;
//     vector<int> books;

// public:
//     int mostBooked(int n, vector<vector<int>>& meetings) {
//         sort(meetings.begin(), meetings.end());
//         // n is very small
//         bookedUntil = vector<int>(n, -1);
//         books = vector<int>(n,0);
//         queue<int> q;   // FIFO, no need extra stuff
//         int START = meetings[0][0], END = meetings[0][1];
//         for (auto m : meetings) {
//             START = min(START, m[0]);
//             END = max(END, m[1]);
//         }

//         int it=0, m = meetings.size();
//         for (int i=START; i<1000; ++i) {
//             // enqeuue all meetings starting on day
//             while (it < m && meetings[it][0] == i) {
//                 q.push(meetings[it][1]);
//             }

//             // check room availability, and also clear up done rooms
//             for (int i=0; i<n; ++i) {
//                 if (q.empty()) break;
//                 if (bookedUntil[i] <= i) bookedUntil[i] = -1;   // free just-done/stale rooms
//                 if (bookedUntil[i] == -1) {
//                     bookedUntil[i] = q.front();
//                     q.pop();
//                     books[i]++;
//                 }
//             }
//         }

//         int ans=0;
//         for (const int& b : books) ans=max(ans, b);

//         return ans;
//     }
// };