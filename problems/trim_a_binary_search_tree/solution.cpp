// https://leetcode.com/problems/trim-a-binary-search-tree/discuss/501234/C%2B%2B%3A-Detailed-explanation.-Recursive-Approach

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return root;
        if (root->val >= L && root->val <= R) {
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            return root;
        }
        if (root->val < L)
            root =  trimBST(root->right, L, R);
        else if (root->val > R)
            root = trimBST(root->left, L, R);
        
        
        return root;
    }
};