class Solution {
   
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return {};
        return recurse(1,n);
    }
    
    vector<TreeNode*> recurse(int start, int end){
        vector<TreeNode*> result;
        if(start > end){
            result.push_back(nullptr);
            return result;
        }
        
        
        for(int i=start; i <= end; i++){
            vector<TreeNode*> left_subtree  = recurse(start, i-1);    // return a vector of all bst's from start to (i-1)
            vector<TreeNode*> right_subtree = recurse(i+1,   end);
            
            for(TreeNode* l: left_subtree){
                for(TreeNode* r: right_subtree){
                    //we give all bst's the new root(i)
                    TreeNode* root = new TreeNode(i);
                    root->left  = l;
                    root->right = r;
                    result.push_back(root);         //and keep track in vector , make new bst's with having root (i)
                }
            }
        }
        
        return result;
    }
};