//level ordr, the point where you get a node with both childNULL, or we can say a leaf node, we break and return the minDepth


class Solution {
public:
    int level = 0;
    int minDepth(TreeNode* root) {
        if(!root){ return 0;}
        
        queue<TreeNode*> q;
        int level = 0;
        
        q.push(root);
        while(!q.empty()){
            int breadth = q.size();
            level++;
            for(int i=0; i<breadth; i++){
                TreeNode* parent = q.front(); 
                q.pop();
                
                if(parent->left) q.push(parent->left);
                if(parent->right) q.push(parent->right);
                
                if(parent->left==NULL and parent->right==NULL) return level; //leaf node
            }
        }
        
        return level;
    }
};