// O(n^2)
class Solution {
public:
    int diameter = 0;
    int height(TreeNode *root) {
        if(root == NULL)return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    
    void solve(TreeNode*root){
        if(!root) return;
        int left = height(root->left);
        int right = height(root->right);
        diameter = max(diameter,(left+right));  //as question mention about edges
        solve(root->left);
        solve(root->right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return diameter;
    }
};




// O(n)
// we just updated code of height function, , we are updating diamter, while finding height

/*
class Solution {
public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        rec(root);
        return ans;  
    }
    
    int rec(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = rec(root->left);
        int rh = rec(root->right);
        
        ans = max(ans , (lh+rh));   //why lh + rh, bcz till now we havent updated for our current node
        return max(lh,rh)+1;
    }
	
};
*/