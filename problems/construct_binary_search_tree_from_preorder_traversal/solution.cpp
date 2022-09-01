// convert bst frpm preorder
// also see: bst from inorder


// approach 1: sort array you get inorder, now you have inorder and preorder
// make tree like : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// TC: o(nlogn) + O(n)


// approach 2: just sort and use : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// bst from inorder



// approach 3: 
// TC: o(n)
// idea: https://leetcode.com/problems/validate-binary-search-tree/
// https://www.youtube.com/watch?v=UmJT3j26t1I


class Solution {
public:
    int idx = 0;  // should be global or passed by reference bcz we will check on left and right both side, so there can be multiple cases for both sides, if we make copies of same index
    
    TreeNode* buildTree(vector<int>&preorder , int ub){
        if(idx==preorder.size() or preorder[idx]>ub)  return NULL;
        
        TreeNode* root = new TreeNode(preorder[idx]);
        idx+=1;
        
        root->left = buildTree(preorder , root->val);  
        root->right = buildTree(preorder , ub);
            
        return root;
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder, int ub = INT_MAX) {
        if(preorder.size()==0) return NULL;
        return buildTree(preorder, INT_MAX);   // preorder, upper bpund
    }
};