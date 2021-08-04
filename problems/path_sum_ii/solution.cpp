//Idea 1: https://leetcode.com/problems/path-sum/
//Code idea: https://leetcode.com/problems/all-paths-from-source-to-target/

//how to avoid backtracking, at every step we are taking care of every node, we are visiting
class Solution {
public:
    
    void dfs(TreeNode* root, vector<vector<int>>& result, vector<int> path, int sum) {  //path is passed by value now(path)...
        
        if (root == NULL) return;
        path.push_back(root->val);
        if (root->right == NULL and root->left ==  NULL){
            if(root->val == sum){
                result.push_back(path);
                
            }
        }
        // for(auto it:path){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        dfs(root->left, result, path, sum - root->val);
        dfs(root->right, result, path , sum - root->val);
        
        // path.pop_back();                                           //no backtracking needed 
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<vector<int>> paths; 
        vector<int> path;
        
        dfs(root, paths, path, sum);
        return paths;
        
    }
};