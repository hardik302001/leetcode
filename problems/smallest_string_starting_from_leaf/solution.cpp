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
    string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzz";   // 27 times z
        
    void recur(TreeNode* root, string &cur){
        if(root==NULL) return;
        
        cur+= char('a' + root->val);
        if(root->left==NULL and root->right==NULL){
            reverse(cur.begin(), cur.end());
            ans = min(ans, cur);
            reverse(cur.begin(), cur.end());
        }
        
        recur(root->left, cur);
        recur(root->right, cur);
        cur.pop_back();                 // backtracking
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string cur = "";
        recur(root, cur);
        return ans;
    }
};