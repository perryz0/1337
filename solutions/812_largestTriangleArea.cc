// Sep. 26th, 2025

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n=points.size();
        // sort(points.begin(), points.end());
        double ans=0;
        for (int i=0; i<n; ++i) { 
            double x1=points[i][0], y1=points[i][1];
            // cout << x1 << "," << y1 << endl;
            for (int j=i+1; j<n; ++j) {
                double x2=points[j][0],y2=points[j][1];
                for (int k=j+1; k<n; ++k) {
                    double x3=points[k][0], y3=points[k][1];
                    double A = 0.5*fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
                    // cout << A << endl;
                    ans=max(ans,A);
                }
            }
        }

        return ans;
    }
};