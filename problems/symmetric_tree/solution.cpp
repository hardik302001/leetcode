//THE CODE IS QUITE SIMILAR TO SAME TREE QUESTION(EASY)
// there we were chceking for every left we traversed left and for every right we traversed //right..but here it is opposite bcz its mirror image ...so for evry left we will check right and //for evry right we will check left

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        
        return checkSymmetric(root->left, root->right);
    }
    
    
    //check the two nodes in symmetric position
    bool checkSymmetric(TreeNode *leftSymmetricNode, TreeNode *rightSymmetricNode)
    {
        if (leftSymmetricNode == NULL && rightSymmetricNode == NULL)
            return true;
        if (leftSymmetricNode == NULL || rightSymmetricNode == NULL)
            return false;
        
        if (leftSymmetricNode->val != rightSymmetricNode->val){
            return false;
        }
        
        return checkSymmetric(leftSymmetricNode->left, rightSymmetricNode->right) and                            checkSymmetric(leftSymmetricNode->right, rightSymmetricNode->left);
        
    }
};