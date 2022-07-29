// post order
// we need path length not nodes, we need edges

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        int longestPath=0;
        go(root, longestPath);
        return longestPath;
    }

    int go(TreeNode* root, int& m){
        
        int l=root->left ? go(root->left, m) : 0;
        int r=root->right ? go(root->right, m) : 0;
        
        int leftpath  = (root->left && root->left->val==root->val) ? l+1 : 0;
        int rightpath = (root->right && root->right->val==root->val) ? r+1 : 0;
        m = max(m,leftpath + rightpath);     // both left and right side are equal to root
        return max(leftpath , rightpath);    // if not equal to root, they will independently search
    }
};