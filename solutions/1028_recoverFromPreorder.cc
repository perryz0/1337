// Feb. 21st, 2025 (daily)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        TreeNode* recoverFromPreorder(string traversal) {
            // convert preorder string into the entire binary tree structure
            // preorder = dfs for trees
            int idx = 0;
            return dfs(idx, traversal, 0);
        }
    
        TreeNode* dfs(int& idx, const string& traversal, int depth) {
            if (idx >= traversal.size()) return nullptr;
    
            // first learn about the current idx and depth (extracted using D, num of dashes)
            int dashes = 0;
            while (traversal[idx] == '-') {
                dashes++; idx++;
            }
    
            // we are trying to find deeper left children
            if (dashes < depth) {
                idx -= dashes;
                return nullptr;
            }
    
            // extract the node value (multi-digit numbers)
            int num = 0;
            while (idx < traversal.size() && isdigit(traversal[idx])) {
                num = num * 10 + (traversal[idx] - '0');
                idx++;
            }

            TreeNode* curr = new TreeNode(num);
            curr->left = dfs(idx, traversal, depth + 1);
            curr->right = dfs(idx, traversal, depth + 1);
    
            return curr;
        }
    };
    