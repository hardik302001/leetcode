// TC: o(N)

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