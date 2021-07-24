//we need bottom up approach, we need to check from leaf node to root, so it is postorder traversal

//TC = O(n)
//SC = O(H)


class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root){
            return NULL;
        }
        
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
   
        if (root->val == 0 && root->left == NULL && root->right == NULL){
            root = NULL;
        }
            
        
        return root;
   
        
    }
};