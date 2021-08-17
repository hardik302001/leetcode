class Solution {
public:
    int c=0;                                   // for count
    void count(TreeNode*root,int val){
        if(!root)return ;

        if(root->val>=val)c++;       // if the current node's value is the maximum value in our current path then increment the current node's value!!

        count(root->left,max(val,root->val));    // do the same for the nodes in the left subtree and update the maximum value in the current path
        count(root->right,max(val,root->val));  // do the same for the nodes in the right subtree and update the maximum value in the current path
    }
    int goodNodes(TreeNode* root) {
       // if(!root)return 0;
        count(root,root->val);
        return c; // return the count
    }
};