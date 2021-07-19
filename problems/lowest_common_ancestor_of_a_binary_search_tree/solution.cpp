/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == NULL) return NULL;
        //if both are more than root->val, then find lca for left part
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        //if both part are more than root->val, then find lca for right part
        if (root->val < p->val  && root->val < q->val)
            return lowestCommonAncestor(root->right,   p , q);
        //now it means p and q are on differnet side node  root of bst, it means root is LCA 
        return root;
    }
};