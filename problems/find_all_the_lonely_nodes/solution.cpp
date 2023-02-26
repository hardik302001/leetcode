class Solution {
    void dfs(TreeNode* root, vector<int>& lonely) {
        if (!root)
            return;
        if (root->left && !root->right)
            lonely.push_back(root->left->val);
        if (!root->left && root->right)
            lonely.push_back(root->right->val);
        dfs(root->left, lonely);
        dfs(root->right, lonely);
    }
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> lonely;
        dfs(root, lonely);
        return lonely;
    }
};