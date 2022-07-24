
class Solution {
public:    
    int maxSum(TreeNode* root, int& ans) {
        /* This function return the Branch Sum......
        So if the node is NULL then it won't have a branch....so the branch sum will be 0.
        */
        //Base Case
        if(root == NULL){
            return 0;
        }

        //Recursive Case 
        int leftBS = maxSum( root->left , ans );     // left maximum path sum
        int rightBS = maxSum( root->right , ans );   // right maximum path sum

        
        // for answer , we will consider all cases..
        ans = max({
                    ans,                         //we may have found the maximum ans already
                    root->val,                   //may be the current root val is the maximum sum possible
                    leftBS + root->val,          //may be the answer contain root->val + left branch value
                    rightBS + root->val,         //may be the answer contain root->val + right branch value
                    leftBS + rightBS + root->val //may be the answer contains root and left and right
                });

        //Return the max branch Sum
        // our function return the maximum path sum between nodes
        // so either we will only have root, or root+left or root + right , [ not both ]
        // bcz if we have both, then it will be our answer and we cant go any further to explore more possiblities
        // we need maximum path sum, not maximum subtree sum
    /*
                 x
                /  \
               y     z
              / \    / \
             p   q   r  s
             
             suppose , for root z, i consider r and s both, and then for next root  x , if i consider rightt subtree
        then it would be like x - z - r  , so there will not be unidirectional path ...
                                  |s 
     */  
        return max({ leftBS + root->val, rightBS +root->val, root->val });   // very important
    }
    

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxSum(root, ans);
        return ans;
    }
};



// --------------------------------------------------------------------------------
// CHILDREN SUM PROPERTY
// also see: https://takeuforward.org/data-structure/check-for-children-sum-property-in-a-binary-tree/
// https://www.youtube.com/watch?v=fnmisPM6cVo

/*
Problem Statement: 
Children Sum Property in a Binary Tree. Write a program that converts any binary tree to one that follows the children sum property.
The children sum property is defined as, For every node of the tree, the value of a node is equal to the sum of values of its children(left child and right child).

Note: 

The node values can be increased by 1 any number of times but decrement of any node value is not allowed.
A value for a NULL node can be assumed as 0.
You are not allowed to change the structure of the given binary tree.

//     Time complexity : O(N)
//     Space complexity : O(N)

//     Where 'N' is the number of nodes.


void changeTree(BinaryTreeNode<int> *root) {

    // Base Cases.
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        return;
    }

    // Calculate the difference between the root and its children.
    int difference = root->data - ((root->left ? root->left->data : 0) + (root->right ? root->right->data : 0));
    
    // if the differnce is positive, increment left and right child node
    
    if (difference > 0) {
        if (root->left) {
            root->left->data += difference;
        }
        if(root->right) {
            root->right->data += difference;
        }
    }

    // Call this function again for the left and right subtree.
    changeTree(root->left);
    changeTree(root->right);

    // Update root with the sum of the left and right child's data.
    root->data =  ((root->left ? root->left->data : 0) + (root->right ? root->right->data : 0));
}


*/