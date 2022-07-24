// TC: o(n)
// idea same as height of tree, just some updates in that code
// courtesy : striver

class Solution {
public:
    int height (TreeNode* root){ 
        if(root==NULL)    return 0;
        
        int lh = height(root->left);
        int rh = height(root->right);
            
        if(lh==-1 or rh==-1) return -1;
        if(abs(lh-rh)>1)     return -1;
        
        return max(lh, rh)+1;
        
    }

    bool isBalanced(TreeNode* root) {
        int ans = height(root);
        return (ans==-1)?false:true;        
    }
};




//TC: O(n^2)
/*
class Solution {
public:
    int height(TreeNode *root) {
        if(root == NULL)return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)return true;
        return isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left) - height(root->right)) <= 1;
    }
};
*/