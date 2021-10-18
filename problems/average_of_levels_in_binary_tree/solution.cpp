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
    vector<double> averageOfLevels(TreeNode* root) {
        if (root == NULL) 
			return {};
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root); 
        while (!q.empty())
        {
            int size = q.size(); 
            long long int s = 0;
            for(int i=0;i<size;i++){          //same level
                TreeNode* tmp=q.front();
                q.pop();
                s = s + (tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            res.push_back(double(s)/size);
            
        }
        return res;
    }
};