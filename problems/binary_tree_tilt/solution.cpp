class Solution {
public:
    int result = 0;
    int depthfirstsearch(TreeNode *root) {    //postorder
        
		//Checking if there are some child tree and if its true dfs it or else the node is leaf node therfore make it 0
        int left = (root->left ? depthfirstsearch(root->left) : 0);
        int right = (root->right ? depthfirstsearch(root->right) : 0);
        
        // Finding the current tilt( |left-right| )
		result += abs(left - right);
		// returning the total sum
        return left + right + root->val;
    }
    int findTilt(TreeNode* root) {
        if (root) depthfirstsearch(root);
        return result;
    }
};