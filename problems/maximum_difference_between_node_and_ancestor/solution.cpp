// also see: https://leetcode.com/submissions/detail/610242445/
// also see: https://leetcode.com/submissions/detail/610195891/
class Solution {
public:
    int ans = 0;
    void recur(TreeNode* root , int ma, int mi){
        if(root==NULL) return ;
        ans = max(ans , abs(root->val - ma));
        ans = max(ans , abs(root->val - mi));
        int maa = max( ma , root->val);
        int mii = min(mi , root->val);
        recur(root->left , maa , mii);
        recur(root->right, maa , mii);
        
    }
    
    int maxAncestorDiff(TreeNode* root) {
        recur(root , root->val, root->val);
        return ans;
    }
};