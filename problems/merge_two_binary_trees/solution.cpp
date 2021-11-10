//SEE PREV SOLN also



//here no extra space, we r directly changing the first tree
//  our motto it traverse until node becomes NULL one any of the tree..
//change in sum comes whn we have both nodes value !=NULL
//so if any of node becomes null, we need not traverse more, and we can return the non NULL node and return
//if both nodes are null, return null.

// if there are no nodes of tree2 we return current t1...bcz we no now there wont be any new changed sum..so total sum for that node =value of  treee1 node
//so we need not traverse more, so we return t1 (and all connected unchsnged nodes after t1 will automatically be there...bcz link exists there..)

// if we get no nodes of tree1...so we connect current t2(and all connected unchsnged nodes after t1 will automatically be there...bcz link exists there..) and we need not traverse more there, bcz we know there will be no change in sum..


class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL and t2==NULL){
            return NULL;
        }
        
        if(t1==NULL or t2 == NULL)
            return t1 == NULL ? t2 : t1;
        
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left,t2->left);
        t1->right = mergeTrees(t1->right,t2->right);
        
        return t1; 
    }
};


