/*
class Solution {
public:


    bool isBalancedOptm(TreeNode* root, int* height){  //height wlaa part optimised.
        int lh = 0;
        int rh = 0;


        if(root==NULL){
            return true;   
        }

        if(isBalancedOptm(root->left, &lh)==false){
            return false;
        }
        if(isBalancedOptm(root->right, &rh)==false){
            return false;
        }

        *height = max(lh, rh)+1;
        if(abs(lh-rh)<=1){
            return true;
        }
        else{
            return false;
        }

    }

    
    
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return isBalancedOptm(root, &height);
        
    }
};

*/



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