/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
int maxSum(TreeNode* root, int& ans) {
    /* This function return the Branch Sum......
    So if the node is NULL then it won't have a branch....so the branch sum will be 0.
    */
    //Base Case
    if(root == NULL){
        return 0;
    }
    
    //Recursive Case 
    //BS = Branch Sum
    int leftBS = maxSum( root->left , ans );
    int rightBS = maxSum( root->right , ans );
    
    ans = max({
                ans,            //we may have found the maximum ans already
                root->val,      //may be the current root val is the maximum sum possible
                leftBS + root->val,         //may be the answer contain root->val + left branch value
                rightBS + root->val,        //may be the answer contain root->val + right branch value
                leftBS + rightBS + root->val  
                                               // Since the root val is added twice from leftBS and rightBS so we are sunstracting it.
            });
    
    //Return the max branch Sum
    return max({ leftBS + root->val, rightBS +root->val, root->val });
}

int maxPathSum(TreeNode* root) {
    int ans = INT_MIN;
    maxSum(root, ans);
    return ans;
}
};