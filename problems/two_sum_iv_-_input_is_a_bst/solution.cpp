// approach 1: do inorder, get it sorted ,store it and do normal 2 sum , 2 pointer
// TC:  O(N)  SC: O(N) 


// approach 2, set + traversal
// TC:  O(N)  SC: O(N) 

/*
class Solution {
public:
    unordered_set<int>s;
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)return false;
        
        if(s.find(k - root->val)!=s.end()){
            return true;
        }
        s.insert(root->val);
        return findTarget(root->left , k) or findTarget(root->right , k);
    }
};
*/


// approach 3 : idea of https://leetcode.com/problems/binary-search-tree-iterator
// introduce concept of before , from https://leetcode.com/problems/binary-search-tree-iterator-ii/
// we are doing 2 pointers, so array need to be sorted, it means it shud be in n order fashion
// for inorder we did , bstiterator to get next element in O(h)
// easily get both left and right pointers and do usual 2 pointer 2 sum
// TC: O(N) , SC= 2*O(H)  : this is optimissation


class BSTIterator {
public:
    stack<TreeNode*> s;
    
    // rev == true means we need right pointer , before()
    // rev == false means we need left pointer , next()
    
    bool rev;
    BSTIterator(TreeNode* root, bool isrev) {
        rev = isrev;
        partialInorder(root);
    }
    
    // go till extreme left/right, bcz inorder is (left root right)/(right root left)
    // depenidng upon rev flag
    void partialInorder(TreeNode* root){
        while(root != NULL){
            s.push(root);          // push in stack
            if(rev==false) root = root->left;
            else           root = root->right;
        }
    }
    
    // consider top of stack , that will be near bottom of tree(leaf node)
    int next() {
        TreeNode* top = s.top();   // consider it as root 
        s.pop();
        if(rev==false)     partialInorder(top->right);  // explore right subtree
        else               partialInorder(top->left);   // explore left subtree
            
        return top->val;
    }
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)return false;
        
        // make objects for 2 pointers
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        
        // we would have used next and before as seperate things, but we want code quality 
        // so rather we used rev flag to do the same thing
        int i = l.next();  // points to beg of inorder   ( smallest )
        int j = r.next();  // points to end of inorder   ( largest )
        
        while(i<j){
            if(i+j==k) return true;
            else if(i+j>k) j = r.next();    // one step back (towards beg)
            else           i = l.next();    // one step front (towarsd end)
        }
        
        return false;        
        
    }
};