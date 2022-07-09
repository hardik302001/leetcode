
class Solution {
public:
bool evaluateTree(TreeNode* root) {
        if(root->val==1) return true;
        if(root->val==0) return false;
        
        bool l=evaluateTree(root->left);
        bool r=evaluateTree(root->right);
        
        if(root->val==3)    return l and r;
        else                return l or  r;
        
    }
};