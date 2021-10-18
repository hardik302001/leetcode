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


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) 
			return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root); 
        while (!q.empty())
        {
            int size = q.size(); 
            vector<int> currlevel;
            for(int i=0;i<size;i++){          //same level
                TreeNode* tmp=q.front();
                q.pop();
                currlevel.push_back(tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            res.push_back(currlevel);
        }
        return res;
    }
};