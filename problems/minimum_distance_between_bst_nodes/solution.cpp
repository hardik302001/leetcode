
// TC : o(N)
// SC : O(1)

class Solution {
public:
    int diff = INT_MAX;
    int prev = -100001;
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root->left);
        diff = min(diff,root->val-prev);
        prev = root->val;
        inorder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return diff;
    }
};