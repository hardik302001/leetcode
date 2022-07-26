// we just need to define the new pointer "next" for the given tree, so we just need to tell that for every node x, what will be x->next !


// OPTMISED SOLN, we are using the next pointers o fprev nodes to build next pointers of cur node
// idea: https://www.youtube.com/watch?v=U4hFQCa1Cq0
// TC: o(N)
// SC: o(1)



class Solution {
public:
    Node* connect(Node* root) {        
        if(root == NULL)
            return NULL;

        if(root->left != NULL) root->left->next = root->right;
        if(root->right != NULL && root->next != NULL) root->right->next = root->next->left;


        connect(root->left);
        connect(root->right);
        return root;
    }
};


// --------------------------------------------------------------

// TC, SC = O(N)
// bfs normal soln
/*
class Solution {
public:
    Node* connect(Node* root) {
        
        if(root==NULL){
            return root;
        }
        
        queue<Node* >q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                Node* x=q.front();
                q.pop();
                if(i!=n-1)x->next=q.front();
                else x->next = NULL;
                
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
            
        }
        
        return root;
    }
};
*/