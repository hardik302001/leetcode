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
    vector<TreeNode*>res;
    unordered_map<string , int>mp;
    string recur(TreeNode* root){
        if(root==NULL) return "";
        string representation = "(" + recur(root->left) + ")" + to_string(root->val) + "(" + recur(root->right) + ")";
        mp[representation]++;
        if(mp[representation]==2) res.push_back(root);
        return representation;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        recur(root);
        return res;
    }
};