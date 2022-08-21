
// BURN THE TREE (similar idea to : Kth distamce nodes in tree)
// make adj for parent


class Solution {
public:
    
   
      
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent_track; // node -> parent
        queue<TreeNode*> queue;
        queue.push(root);
        
        TreeNode* target = NULL;
        while(!queue.empty()) {   //First BFS to get a track of parent nodes
            TreeNode* current = queue.front(); queue.pop();
            if(current->val==start) target = current;
            
            if(current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if(current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
        
        
      
      
        queue.push(target);
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;
        int curr_level = 0;
        while(!queue.empty()) {   //Second BFS to go upto K level from target node and using our hashtable info
            int size = queue.size();
            
            while(size--) {
                TreeNode* current = queue.front(); queue.pop();
                // cout<<current->val<<endl;
                if(current->left && !visited[current->left]) {   // left
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]) {  // right
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]) {   // parent
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
            curr_level++;
        }
        
        return curr_level-1;
    }

};