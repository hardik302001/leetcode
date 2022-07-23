// dfs

class Solution{
public:
    int depth(TreeNode *root) {
        if (!root) return 0;
        return max(depth(root->left),depth(root->right))+1;
    }

    void levelOrder(vector<vector<int>> &ans, TreeNode *node, int level) {
        if (!node) return;
        ans[level].push_back(node->val);
        levelOrder(ans,node->left,level-1);
        levelOrder(ans,node->right,level-1);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int d = depth(root);
        vector<vector<int>> ans(d,vector<int> {});
        levelOrder(ans,root,d-1);
        return ans;
    }

};


// dfs + reverse
// same concept is also used in right view question : https://leetcode.com/problems/binary-tree-right-side-view/
/*
class Solution{
public: 
    vector<vector<int>>res;
    
    void recur(TreeNode* root, int depth){
        if(root==NULL) return ;
        if(depth==res.size()){
            res.push_back(vector<int>{});
        }
        
        res[depth].push_back(root->val);
        recur(root->left , depth+1);
        recur(root->right, depth+1);
        
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL) 
            return {};
        
        recur(root, 0);
        reverse(res.begin(), res.end());
        return res;
    } 
};

*/


// bfs + reverse
/*
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL) 
			return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root); 
        while (!q.empty())
        {
            int size = q.size(); 
            vector<int> currlevel;
            for(int i=0;i<size;i++){
                TreeNode* tmp=q.front();
                q.pop();
                currlevel.push_back(tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            res.push_back(currlevel);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
*/