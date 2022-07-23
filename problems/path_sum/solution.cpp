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



// also see: https://www.interviewbit.com/problems/path-to-given-node/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int target) {
        if(root==NULL) return false;
        
        target -= root->val;
        if(target==0 and root->left==NULL and root->right==NULL) return true;

        return hasPathSum(root->left , target) or hasPathSum(root->right , target);
        
    }
};