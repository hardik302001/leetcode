// without reverse operation
// O(n)
// striver video


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        
        bool leftToRight = true;
        
        while(!q.empty()){
            int sz = q.size();
            vector<int>level(sz);
            for(int i = 0;i<sz;i++){
                int ind;
                if(leftToRight){
                    ind = i;
                }else{
                    ind = sz-1-i; 
                }
                
                auto top = q.front();
                q.pop();
                
                level[ind] = top->val;
                if(top->left)         q.push(top->left);
                if(top->right)        q.push(top->right);
            }
            ans.push_back(level);
            leftToRight = !leftToRight;
        }
        return ans;
    }
};