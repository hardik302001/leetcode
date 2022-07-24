// O(n) , i guess

/*
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        
        flatten(root->left);
        flatten(root->right);
        
        TreeNode *tmp = root->right;  // head of right side
        root->right = root->left;    // put flattened left on right side
        root->left = NULL;           // mark left side as NULL 
        while (root->right)         // now traverse to end of left flattened(that is on right side now)
            root = root->right;
        
        root->right = tmp;             // attached head of flattened right side to tail of flattened left side
    }
};
*/

// ---------------------------------------------------------

// approach 2 by striver
// this is confirm O(n)
// TC, SC = o(N)

// there is also a new solution where SC = O(1) , iterative stack morris traversal something... maybe see that also

class Solution {
public:
    
    TreeNode* prev = NULL;     // pointing to end of flattened tree
    void flatten(TreeNode* root) {
        if (!root) return;
        
        
        // bcz our priority is right, we want righ sided binary tree
        flatten(root->right);    // explore right first
        flatten(root->left);     // then left
        
        root -> right = prev;
        root -> left = NULL;
        prev = root;
        
    }
};