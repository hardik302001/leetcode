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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<int> curLeaves; //get current level leaves
        vector<vector<int>> allLeaves;
        while(root != NULL){
            curLeaves.clear();
            root = getLeaves(root, curLeaves);
            allLeaves.push_back(curLeaves);
        }
        return allLeaves;
    }

    TreeNode* getLeaves(TreeNode* root, vector<int>& curLeaves){
        if(root == NULL)
            return NULL;
        //Check if current node is a leaf
        if(root->left == NULL && root->right == NULL){
            curLeaves.push_back(root->val);
            return NULL; //Making leaf node as NULL
        }
        root->left = getLeaves(root->left, curLeaves);
        root->right = getLeaves(root->right, curLeaves);

        return root;
    }
};