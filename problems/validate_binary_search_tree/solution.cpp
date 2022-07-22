
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

//---------------------------------------------------------------------------

//inorder should be sorted

/*
class Solution {
public:
    vector<int>inord;
    bool isValidBST(TreeNode* root) {
        
        inorder(root);
        bool f = true;
        for(int i = 0;i<inord.size()-1;i++){
            if(inord[i]>=inord[i+1]){
                f = false;
                break;
            }
        }
        
        
        return f;
    }
    
    
    void inorder(TreeNode * root){
        if(root==NULL){
            return ;
        }
        inorder(root->left);
        inord.push_back(root->val);
        inorder(root->right);
    }
};
*/