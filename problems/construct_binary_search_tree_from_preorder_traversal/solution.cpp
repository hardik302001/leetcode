

/*


        O(n) Solution
In the solution above, we are searching for a split point to divide the interval. Instead, we can pass the parent value to the recursive function to generate the left sub-tree. The generation will stop when the value in the preorder array exceeds the parent value. That will be our split point to start generating the right subtree.

    
    */
class Solution {
public:

int idx = 0;
TreeNode* bstFromPreorder(vector<int>& preorder, int p_val = INT_MAX) {
    if (idx >= preorder.size() || preorder[idx] > p_val)
        return nullptr;
    auto n = new TreeNode(preorder[idx++]);
    n->left = bstFromPreorder(preorder, n->val);
    n->right = bstFromPreorder(preorder, p_val);
    return n;
}
    
};