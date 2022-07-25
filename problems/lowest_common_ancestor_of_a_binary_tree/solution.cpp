
// brute force is to write path from root to both nodes, https://www.interviewbit.com/problems/path-to-given-node/
// then do 2 pointer matching
// 2 traversal, TC = O(N) , SC = O(N)




// optimised
// TC: O(n) , SC :o(1)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root->val == p->val or root->val==q->val)return root;
        
        TreeNode* left = lowestCommonAncestor(root->left , p , q);
        TreeNode* right = lowestCommonAncestor(root->right , p , q);
        
        
        if(left==NULL and right==NULL) return NULL;
        if(left!=NULL and right!=NULL) return root;
        if(left!=NULL) return left;
        if(right!=NULL) return right;
        
        return NULL;
    }
};