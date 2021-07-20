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
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
        
        if (root->right == NULL and root->left ==  NULL){
            if(root->val == sum){
                return true;
            }
            else{
                return false;
            }
        }
        
        return hasPathSum(root->left, sum - root->val) or hasPathSum(root->right, sum - root->val);
    }
};