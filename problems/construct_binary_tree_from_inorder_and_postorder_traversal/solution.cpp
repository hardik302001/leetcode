//  https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/discuss/758462/C%2B%2B-Detail-Explain-or-Diagram



//Use HashMap to reduce the time complexity to O(n)

class Solution {
public:
    unordered_map<int, int> Map;
    TreeNode* build(int inS, int inE, vector<int>& inorder, int poS, int poE, vector<int>& postorder ) {
        if (inS > inE || poS > poE) return NULL;
        int index = Map[postorder[poE]];
        TreeNode* root = new TreeNode(inorder[index]);
        root->right = build(index+1, inE, inorder, poE + index - inE, poE - 1, postorder);
        root->left =  build (inS, index - 1, inorder, poS, poE+index-inE - 1, postorder);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            Map[inorder[i]] = i;
        return build(0, inorder.size() - 1, inorder, 0, postorder.size() - 1, postorder);
    }
};