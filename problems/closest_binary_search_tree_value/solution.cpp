class Solution {
public:
    void getResult(TreeNode *node, double target, double &result){
        if(!node)return;
        if(abs((double)node->val-target)<abs(target-result))result=(double)node->val;
        if((double)node->val>target)
            getResult(node->left,target,result);
        else if((double)node->val<target)
            getResult(node->right,target,result);
    }
    int closestValue(TreeNode* root, double target) {
        double result=(double)root->val;
        getResult(root,target,result);
        return (int)result;
    }
};