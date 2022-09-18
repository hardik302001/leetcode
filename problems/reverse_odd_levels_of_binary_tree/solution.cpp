// bfs, 
// its a perfect tree


class Solution {
public:  
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL) return root;
        queue<TreeNode* >q;
        q.push(root);
        int f = 1;   
        while(q.size()){
            int sz = q.size();
            vector<TreeNode*>temp;
            while(sz--){
                auto cur = q.front();q.pop();
                if(cur->left){ q.push(cur->left);temp.push_back(cur->left);}
                if(cur->right){ q.push(cur->right); temp.push_back(cur->right);}
            }
            
            if(f){
                for(int i = 0;i<temp.size()/2;i++){
                    swap(temp[i]->val, temp[temp.size()-i-1]->val);    
                }
            }
            
            f = 1-f;
        }
        
        
        return root;
    }
};