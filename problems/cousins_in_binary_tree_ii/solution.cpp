// total sum at lvl - sum of sibling ( track with help of parent)
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int>level;
        queue<TreeNode*>q;
        q.push(root);
        unordered_map<TreeNode*, TreeNode*>par;
        unordered_map<TreeNode*, int>vals;  // bcz value will get update on fly
        par[root] = NULL;
        while(q.size()){
            int sz = q.size();
            int s = 0;
            while(sz--){
                auto cur = q.front();
                vals[cur] = cur->val;
                q.pop();
                s+=cur->val;
                if(cur->left) {q.push(cur->left); par[cur->left] = cur;}
                if(cur->right) {q.push(cur->right) ; par[cur->right] = cur;}
            }
            level.push_back(s);
        }

        q.push(root);
        int i = 0;
        while(q.size()){
            int sz = q.size();
            int s = 0;
            while(sz--){
                auto cur = q.front();
                q.pop();
                long long curs = level[i];
                if(par[cur]!=NULL){ 
                    if(par[cur]->left){
                        curs-=vals[par[cur]->left];
                    }
                    if(par[cur]->right){
                        curs-=vals[par[cur]->right];
                    }
                    cur->val = curs;    // replace

                }else{
                    cur->val = 0;
                }         
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                
            }
            i++;
        }
        
        return root;
        
    }
};