// Mar. 24th, 2025 (daily)

class Solution {
    public:
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            // no rectangles overlap
            // so we just process the ranges
            vector<pair<int,int>> xranges;
            vector<pair<int,int>> yranges;
    
            for (auto& r : rectangles) {
                xranges.push_back({r[0],r[2]});
                yranges.push_back({r[1],r[3]});
            }
    
            sort(xranges.begin(), xranges.end());
            sort(yranges.begin(), yranges.end());
    
            int sz = rectangles.size();
    
            // try find the 2 placements for x, then y
            int xe = xranges[0].second;
            // int xs = xranges[0].first, xe = xranges[0].second;
            int cnt = 0;
            for (int i = 1; i<sz; ++i) {
                
                // cout << xranges[i].first << " " << xranges[i].second << endl;
    
                if (xranges[i].first<xe) {
                    // xs = min(xs,xranges[i].second);
                    xe = max(xe,xranges[i].second);
                    // cout << "updated to " << xs << " " << xe << endl;
                } else {
                    cnt++;
                    // cout << "cnt for x: " << cnt << " at iter " << i << endl;
                    xe=xranges[i].second;
                    // xs=xe;
                }
            }
            if (cnt >= 2) return true;
    
            // cout << "\nprocessing y now\n" << endl;
    
            cnt = 0;
            int ye = yranges[0].second;
            // int ys = yranges[0].first, ye = yranges[0].second;
            for (int i = 1; i<sz; ++i) {
                // cout << yranges[i].first << " " << yranges[i].second << endl;
                if (yranges[i].first<ye) {
                    // ys = min(ys,yranges[i].second);
                    ye = max(ye,yranges[i].second);
                    // cout << "updated to " << ys << " " << ye << endl;
                } else {
                    cnt++;
                    // cout << "cnt for y: " << cnt << " at iter " << i << endl;
                    ye=yranges[i].second;
                    // ys=ye;
                }
            }
            if (cnt>=2) return true;
    
            return false;
        }
    };