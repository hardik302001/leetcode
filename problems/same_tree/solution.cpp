//THE CODE IS QUITE SIMILAR TO SYMMETRIC TREE QUESTION(EASY)
// here we will chceking for every left we traversed left and for every right we traversed //right..but there it is opposite bcz its mirror image ...so for evry left we will check right and //for evry right we will check left


//  https://leetcode.com/problems/symmetric-tree/submissions/

class Solution {
public:
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL and root2==NULL)
            return true;
        
        if (root1 == NULL || root2 == NULL)
            return false;
        
        if (root1->val != root2->val){
            return false;
        }
        
        return isSameTree(root1->left, root2->left) and  isSameTree(root1->right, root2->right) ;                     
    }
};