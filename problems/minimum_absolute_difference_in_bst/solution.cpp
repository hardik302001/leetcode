/*
// TC : o(N)
// SC : O(N)

class Solution {
public:
    
    vector <int> inord;  // stores the nodes visited under inorder walk
    
    void inorder(TreeNode* root) {
        if(root == NULL) return;
        
        inorder(root->left);
        inord.push_back(root->val);
        inorder(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        inord.clear();
        int mini = INT_MAX;  // largest possible minimum value 
        
        inorder(root);
        
        for(int i = 0; i < inord.size() - 1 ; i++) {
            mini = min(inord[i+1] - inord[i], mini);  // minimum of the previous minimum and present possibility
        }
        
      return mini;
    }
};
*/

// TC : o(N)
// SC : O(1)

class Solution {
public:
    int diff = INT_MAX;
    int prev = -100001;
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root->left);
        diff = min(diff,root->val-prev);
        prev = root->val;
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return diff;
    }
};