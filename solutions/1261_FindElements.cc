// Feb. 20th, 2025 (daily)

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
class FindElements {
    private:
        unordered_set<int> vals;
    
    public:
        FindElements(TreeNode* root) {
            vals.insert(0);
            preOrder(root->left, true, 0);
            preOrder(root->right, false, 0);
        }
        
        bool find(int target) {
            return (vals.find(target) != vals.end());
        }
    
        void preOrder(TreeNode* curr, bool isLeft, int x) {
            if (curr == nullptr) return;
    
            if (isLeft) curr->val = 2*x+1;
            else curr->val = 2*x+2;
            vals.insert(curr->val);
            preOrder(curr->left, true, curr->val);
            preOrder(curr->right, false, curr->val);
        }
    };
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */