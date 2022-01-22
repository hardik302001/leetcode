// we just need to define the new pointer "next" for the given tree, so we just need to tell that for every nide x, what will be x->next !


// read the O(1) space soln from discuss, i have not done it...


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