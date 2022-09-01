
// also see: 2 sum (IV) leetcode
// alse see: bst iterator 2 leetcode (here do right root left)



// approach 1: store inorder and then answer next and hasNext in O(1)
// SC = O(n)


// approach 2: we want answer in O(h) , where h is height space
// so we cant store full tree

// we use a stack and we will do partial iterative inorder traversal
// idea: https://leetcode.com/problems/binary-search-tree-iterator/discuss/1430547/C++-Simple-Solution-using-Stack-O(h)-Time-Complexity-(-with-Diagrammatic-Explanation-)
// also see: L50 BST Iterator striver video


class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        partialInorder(root);
    }
    
    // go till extreme left, bcz inorder is left root right
    void partialInorder(TreeNode* root){
        while(root != NULL){
            s.push(root);          // push in stack
            root = root->left;
        }
    }
    
    // consider top of stack , that will be near bottom of tree(leaf node)
    int next() {
        TreeNode* top = s.top();   // consider it as root 
        s.pop();
        partialInorder(top->right);  // explore right subtree
        return top->val;
    }
    
    // if stack is empty , it means inorder traversal is finished,
    bool hasNext() {
        return !s.empty();
    }
};
