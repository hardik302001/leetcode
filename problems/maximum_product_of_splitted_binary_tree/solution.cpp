// tot - for every subarray (post order)
class Solution {
public:
    int mod = 1000000007;
    long long tot = 0;
    long long ma = 0;
    long long recur(TreeNode* root){
        if(root==NULL) return 0;
        long long ls = recur(root->left);
        long long rs = recur(root->right);
        return root->val + ls + rs;
    }
    
    long long subsum(TreeNode* root){
        if(root==NULL) return 0;
        long long ls = subsum(root->left);
        long long rs = subsum(root->right);
        ma = max(ma , (tot - ls)*ls);
        ma = max(ma , (tot - rs)*rs);

        return root->val + ls + rs;
    }
    
    int maxProduct(TreeNode* root) {
        tot = recur(root);
        subsum(root);
        return ma%mod;
        
    }
};