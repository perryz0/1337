// Sep. 1st, 2025

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // each point might be involved in multiple rectangles
        // BRUTE FORCE
        // checking combs of 1 point with every other point = n(n-1)/2, works for n=50
        // checking no other point exists would be n^2(n-1)/2 < n^3 <= 125000, n^3 is ok then
        int ans=0;
        int n=points.size();

        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (i==j) continue;
                int ix=points[i][0], iy=points[i][1];
                int jx=points[j][0], jy=points[j][1];

                if (ix > jx || iy < jy) continue;
                
                // check if any points are within
                bool valid=true;
                for (int k=0; k<n; ++k) {
                    if (i==k || j==k) continue;
                    int kx=points[k][0], ky=points[k][1];
                    // check if its inside
                    if (kx >= ix && kx <= jx && ky >= jy && ky <= iy) {
                        valid=false;
                        break;
                    }
                }

                ans += valid;
            }
        }

        return ans; // not double count because of heuristics (point_i must be left-up of point_j)
    }
};