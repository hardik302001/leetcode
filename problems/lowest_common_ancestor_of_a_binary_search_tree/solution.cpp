
// optimised
// TC: O(h) , height of tree
// idea: https://www.youtube.com/watch?v=cX_kPV_foZc&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=48

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root->val == p->val or root->val==q->val) return root;   // base case
        
        TreeNode* left = lowestCommonAncestor(root->left , p , q);
        TreeNode* right = lowestCommonAncestor(root->right , p , q);
        
        // usually we explore both sides, but here we explore only one of the sides
        if(root->val > p->val and root->val > q->val){
            return left;
        }
        if(root->val < p->val and root->val < q->val){
            return right;
        }
        
        return root;         // p and q are on different sides of root, so root is LCA
    }
};


// ---------------------------------------------------------------------------

// brute force will the normal lca, O(n)
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/
// TC: O(n) , SC :o(1)
/*
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

*/