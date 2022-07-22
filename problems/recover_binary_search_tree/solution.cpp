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
    TreeNode *node_1 = NULL, *node_2 = NULL, *prev = NULL;

    void recoverTree(TreeNode* root) {
        if (root == NULL) return;  
        inorder(root);
        if (node_1 && node_2)
            swap(node_1->val, node_2->val);
    }

    void inorder(TreeNode *root) {
        if (root == NULL) return;
        inorder(root->left);
        if (prev != NULL && root->val < prev->val) { // bcz its inorder, so cur>pre, bcz it is increasingly sorted
            if (node_1 == NULL) {
                node_1 = prev;
            } 
            if (node_1 != NULL) {
                node_2 = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
        
};