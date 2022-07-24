// COURTESY : TECH DOSE
// TC = O( (logn)^2 ), bcz we traverse atmax logn times (bcz logn nodes if lh!=rh) brutely, and logn  time to find height evertime

// SC = O(h) = O(logn)

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int lh = findHeightLeft(root);  //height uptil left most corner node in left subtree
        int rh = findHeightRight(root);  //height uptil right most corner node in right subtree
        
        if(lh==rh) return (1<<lh)-1;   //means it is a complete tree , so direcly 2*h -1
        return 1 + countNodes(root->left) + countNodes(root->right);  //else we again check brutely!
    }
    
    int findHeightLeft(TreeNode* node){
        int ht = 0;
        while(node){
            ht++;
            node= node->left;
        }
        return ht;
    }
    
    int findHeightRight(TreeNode* node){
        int ht = 0;
        while(node){
            ht++;
            node= node->right;
        }
        return ht;
    }
};



// O(n) = count nodes
// O(h) = logn space comp
/*
class Solution {
public:
    int c = 0;
    void count(TreeNode* root){
        if(root==NULL){
            return ;
        }
        else{
            c++;
        }
        count(root->left);
        count(root->right);
    }
    int countNodes(TreeNode* root) {
        count(root);
        return c;
    }
};
*/