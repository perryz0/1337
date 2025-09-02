// Aug. 31st, 2025

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        priority_queue<pair<double,int>> pq;
        for (int i=0; i<n; ++i) {
            double curAvg = (double)classes[i][0]/classes[i][1];
            double nextAvg = (double)(classes[i][0]+1)/(classes[i][1]+1);
            // cout << avg << endl;
            pq.push({nextAvg-curAvg, i});
        }

        // cout << " ----------------------- " << endl;

        for (int i=0; i<extraStudents; ++i) {
            auto [bestRatio, classID] = pq.top();
            // cout << "currBestRatio: " << bestRatio << ", class: " << classID << endl;
            pq.pop();
            int& p=classes[classID][0];
            int& t=classes[classID][1];
            double oldAvg = (double)(p)/(t);
            // cout << "old pass and tot: " << p << " " << t << endl;
            classes[classID][0]++;
            classes[classID][1]++;
            // cout << "new pass and tot: " << p << " " << t << endl;
            double newAvg = (double)(p)/(t);
            double nextAvg = (double)(p+1)/(t+1);
            // cout << "newAvg: " << newAvg << endl;
            pq.push({nextAvg-newAvg, classID});
        }

        double ans=0;
        // while (!pq.empty()) {
        //     auto [avg, id] = pq.top();
        //     ans += avg;
        //     cout << avg << endl;
        //     pq.pop();
        // }
        for (const auto& c : classes) {
            double p=c[0], t=c[1];
            ans += (p/t);
        }

        return ans/n;
    }
};










        // // greedy? always assign to the class with the least number of total
        // int MIN=classes[0][1];
        // int idx=0;
        // int n=classes.size();
        // for (int i=1; i<n; ++i) {
        //     int t=classes[i][1];
        //     if (MIN > t) {
        //         MIN=t;
        //         idx=i;
        //     }
        // }

        // // now add to the smallest class, ALL THE STUDENTS
        // classes[idx][0] += extraStudents;
        // classes[idx][1] += extraStudents;

        // double ans=0;
        // for (const auto& c : classes) {
        //     double p=c[0], t=c[1];
        //     ans += (p/t);
        // }

        // return ans/n;