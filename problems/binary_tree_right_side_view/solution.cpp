
class Solution {
public:
    void dfs(TreeNode* root, int lv, vector<int> &res){
        if(!root)   return;
        if(lv==res.size()) res.push_back(root->val);  // at every kevel we can onlu=y consider one elemenet! 
        dfs(root->right,lv+1,res);  //priority is right side
        dfs(root->left,lv+1,res); // then we go to keft side it right side is null
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
};



/*
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> view;
        queue<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty()) {
            int n = todo.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = todo.front();
                todo.pop();
                if (i == n - 1) {
                    view.push_back(node -> val);
                }
                if (node -> left) {
                    todo.push(node -> left);
                }
                if (node -> right) {
                    todo.push(node -> right);
                }
            }
        }
        return view;
    }
};

*/