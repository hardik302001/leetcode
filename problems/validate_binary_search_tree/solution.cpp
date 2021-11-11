  //see prev submission
class Solution {
public:
    bool isValidBST(TreeNode* root, long long int min = LONG_MIN, long long int max = LONG_MAX) {
        if(root==NULL){
            return true;
        }
        
        if(root->val <= min){
            return false;
        }
        
        
        if(root->val >= max){
            return false;
        }
        
        
        return ( isValidBST(root->left, min, root->val) and isValidBST(root->right, root->val, max) );
    }
};

