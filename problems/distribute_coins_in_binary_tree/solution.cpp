// https://leetcode.com/problems/distribute-coins-in-binary-tree/discuss/221939/C%2B%2B-with-picture-post-order-traversal

class Solution {
public:
    int moves = 0;
    int distributeCoins(TreeNode* root) {
        recur(root);   // it will always give 0, bcz we have same nodes as coins, so after distribution we will end up with 0 coins    
        return moves;
    }
    
    int recur(TreeNode * root){
        if(root==NULL){
            return 0;
        }
        int l = recur( root->left);
        int r = recur(root -> right);
        moves = moves + abs(l) + abs(r);  // moves from left and right subtree
        return l + r - 1 + root->val;
    }
};