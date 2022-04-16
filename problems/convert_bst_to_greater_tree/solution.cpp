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


/*
Before diving into the given solution, you first should know a basic property of BST: inorder traverse of BST will give an ascending sequence of all values.

By slightly modifying the inorder traverse such that we firstly travel right subtree and then left subtree, we can get the descending order of the BST.

That is, before encoutering the current node, we have exactly visited all the values that greater than it. So we just need to set a variable(cur_sum) to keep track the summation of the visited nodes.


*/
class Solution {

private:

    int cur_sum = 0;

public:

    void travel(TreeNode* root){

        if (!root) return;

        if (root->right) travel(root->right);

        

        root->val = (cur_sum += root->val);

        if (root->left) travel(root->left);

    }

    TreeNode* convertBST(TreeNode* root) {

        travel(root);

        return root;

    }

};
        
    
