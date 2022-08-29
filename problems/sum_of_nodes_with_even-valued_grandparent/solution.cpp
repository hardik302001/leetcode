
// also see : similar problem : https://leetcode.com/discuss/interview-question/1230148/amazon-online-onsite-sum-of-nodes-whose-kth-parent-is-even

// other way to do same thing

class Solution {
public:
    int s=0;
    void find(TreeNode *gp,TreeNode *p, TreeNode * child)
    {
        if(child==NULL) return; 
        if(gp!=NULL&&gp->val%2==0){ s+=child->val;} 
        //make parent to gp, child to parent ,child= child->child 
        find(p,child,child->left);
        find(p,child,child->right);
    }
    int sumEvenGrandparent(TreeNode* root) { 
        
        find(NULL,NULL,root);  //we are passing grandparent(gp),parent(p),child
        return s;
    }
};


// ------------------------------------

/*
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
	
        if(root==NULL) 
		     return 0;
        
        int sum=0;
        
		//check node with even-valued grandparent add grandchildren value in sum if exist
		
        if(root->val%2==0){
            if(root->left!=NULL && root->left->left!=NULL)
                sum+=root->left->left->val;
            if(root->left!=NULL && root->left->right!=NULL)
                sum+=root->left->right->val;
            if(root->right!=NULL && root->right->right!=NULL)
                sum+=root->right->right->val;
            if(root->right!=NULL && root->right->left!=NULL)
                sum+=root->right->left->val;
        }
		
		//dfs
        sum+=sumEvenGrandparent(root->left); 
        sum+=sumEvenGrandparent(root->right); 
		
        return sum;
    }
};

*/