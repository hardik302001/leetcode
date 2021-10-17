//see prev solns


class Solution {
public:
    
    void dfs(TreeNode* root, vector<vector<int>>& result, vector<int> &path, int sum) {
        if (root == NULL) return;
        path.push_back(root->val);
        if (root->right == NULL and root->left ==  NULL){            //bcz we need till leaf
            if(root->val == sum){
                result.push_back(path);
            }
        }
        dfs(root->left, result, path, sum - root->val);
        dfs(root->right, result, path , sum - root->val);
        
        path.pop_back();
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<vector<int>> paths; 
        vector<int> path;
        
        dfs(root, paths, path, sum);
        return paths;
        
    }
};