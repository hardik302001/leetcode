/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// TC = O(n)
// SC = o(n) : skew



class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector < int > inOrder;
        stack < TreeNode * > s;
        while (true) {
            if (root != NULL) {
                s.push(root);
                root = root -> left;
            } else {
                if (s.empty()) break;
                root = s.top();
                inOrder.push_back(root -> val);
                s.pop();
                root = root -> right;
            }
        }
      return inOrder;
    }


};

/*
class Solution {
public:

    vector<int>ans;
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    
    
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
        
    }
};
*/