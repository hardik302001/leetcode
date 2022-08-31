class Solution {
public:
    
    // Chcecking in Post Order
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) 
    {
        if (root->left)     //If left Exists
        {
            TreeNode* lNode = removeLeafNodes(root->left, target);      //Check for left
            root->left = lNode;     //Set left node as Null
        }
        
        if (root->right)    //If right Exists
        {
            TreeNode* rNode = removeLeafNodes(root->right, target);     //Check for right
            root->right = rNode;    //Set right node as Null
        }
        
        if (root->val == target && root->left == NULL && root->right == NULL)   //Check for target and make sure it has no Child
        {
            return NULL;
        }
        
        return root;
    }
};