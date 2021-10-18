// https://leetcode.com/problems/house-robber-iii/discuss/1116157/Some-Intuition-With-Pictures-May-be-this-could-help
//awesome code!

class Solution {
public:

    int rob(TreeNode* root) 
    {
        pair<int,int> ans = sub(root);
        return max(ans.first , ans.second);
    }
    
    
    pair<int,int> sub(TreeNode *root)
    {
        if(!root)
            return {0,0};
        
        pair<int,int> leftChildAnswer = sub(root->left);
        pair<int,int> rightChildAnswer= sub(root->right);
        
        int best_If_ParentValueIncluded    =  root->val + leftChildAnswer.second + rightChildAnswer.second;

        int best_If_ParentValueNotIncluded =  max(rightChildAnswer.first , rightChildAnswer.second)
                                              + max(leftChildAnswer.first , leftChildAnswer.second);
        
        return {best_If_ParentValueIncluded , best_If_ParentValueNotIncluded};
    }
    
};

// paste this tc in custom tc console and use tree visualiser: [100,1,2,null,null,null,1,null,100]
 
