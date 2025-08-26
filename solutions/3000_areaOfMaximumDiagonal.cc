// Aug. 25th, 2025

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        vector<double> diags(dimensions.size(), 0);
        for (int i=0; i<dimensions.size(); ++i) {
            int a=dimensions[i][0], b=dimensions[i][1];
            diags[i]=sqrt(a*a+b*b);
            // cout << "pair " << dimensions[i][0] << ","  << dimensions[i][1] << ": " << diags[i] << endl;
        }

        int ans=0;
        double curr=0;
        for (int i=0; i<diags.size(); ++i) {
            // cout << diags[i] << " vs " << curr << endl;
            if (diags[i] >= curr) {
                int A=dimensions[i][0]*dimensions[i][1];
                if (diags[i] == curr) {
                    ans=max(A,ans);
                    continue;
                }

                // diag strictly greater must commit
                curr=diags[i];
                ans=A;
            }
        }

        return ans;
    }
};