// also see : https://leetcode.com/problems/kth-smallest-element-in-a-bst/

// idea:  https://www.youtube.com/watch?v=f-sj7I5oXEI&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=47
// no extra space

class Solution {
public:
    bool isValidBST(TreeNode* root, long long int min = LONG_MIN, long long int max = LONG_MAX) {
        if(root==NULL)        return true;
        if(root->val <= min)  return false;
        if(root->val >= max)  return false;
        return ( isValidBST(root->left, min, root->val) and isValidBST(root->right, root->val, max) );
    }
};

//---------------------------------------------------------------------------

//inorder should be sorted
// but extra space

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