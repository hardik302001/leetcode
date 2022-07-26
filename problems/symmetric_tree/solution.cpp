//THE CODE IS QUITE SIMILAR TO SAME TREE QUESTION(EASY) : https://leetcode.com/problems/same-tree/
// there we were chceking for every left we traversed left and for every right we traversed //right..but here it is opposite bcz its mirror image ...so for evry left we will check right and //for evry right we will check left

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        
        return checkSymmetric(root->left, root->right);
    }
    
    
    //check the two nodes in symmetric position
    bool checkSymmetric(TreeNode* p, TreeNode* q) {
        if((p and !q) or (!p and q)) return false;
        if(!p and !q) return true;
        
        if(p->val!= q->val) return false;
        return checkSymmetric(p->left , q->right) and checkSymmetric(p->right , q->left);    // here changed
    }
};