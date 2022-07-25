// Here we do a postorder traversal, we will calculate the sum of nodes in left sub tree and cnt of nodes in left subtree , as well as for right subtree and use this to root.
// Time complexity: O(n)

class Solution {
public:
    int ans = 0;
    pair<int,int> solve(TreeNode* root){
        if(root==NULL) return {0,0};
        
        auto left = solve(root->left);
        int l_sum = left.first; // sum of nodes present in left sub tree
        int l_cnt = left.second; // no. of nodes present in left sub tree
        
        auto right = solve(root->right);
        int r_sum = right.first; // sum of nodes present in right sub tree
        int r_cnt = right.second; // no. of nodes present in left sub tree
        
        int sum = root->val + l_sum + r_sum;
        int cnt = l_cnt + r_cnt + 1;
        
        if(root->val == sum/cnt) ans++;
        return {sum,cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};










//----------------------------------------------------------------------------

// Time complexity : O(n^2)
/*
class Solution {
public:
    int ans = 0;
    void solve(TreeNode* root){
        if(root==NULL) return;
        int avg = sum(root)/cnt(root);
        if(avg==root->val) ans++;
        solve(root->left);
        solve(root->right);
    }
    
    int cnt(TreeNode* root){
        return !root ? 0 : 1 + cnt(root->left) + cnt(root->right);
    }
    
    int sum(TreeNode* root){
        return !root ? 0 : root->val + sum(root->left) + sum(root->right);
    }
    
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};
*/