// also see: https://leetcode.com/discuss/study-guide/1886481/minimum-time-taken-to-burn-the-binary-tree-from-a-node
// the res is to get the start node, bcz we are given the data, not the node address

// idea : https://www.youtube.com/watch?v=2r5wLmQfD6g&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=32


/*
// BFS APPROACH : 
// find parents and and left and right , and then traverse in bfs manner to find kth distannce nodes
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> parent_track; // node -> parent
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) {   //First BFS to get a track of parent nodes
            TreeNode* current = queue.front(); queue.pop();
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
            if(curr_level == K) break;
            while(size--) {
                TreeNode* current = queue.front(); queue.pop();
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
        
        vector<int> result;
        while(!queue.empty()) {
            TreeNode* current = queue.front(); queue.pop();
            result.push_back(current->val);
        }
        return result;
    }

};

*/


// DFS

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track; // node -> parent
        queue<TreeNode*> queue;
        queue.push(root);

        while(!queue.empty()) {  // First BFS to get a track of parent nodes 
            TreeNode* current = queue.front(); queue.pop();
            if(current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if(current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
        
        
        vector<int>ans;
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;
        dfs(target , k, ans, parent_track , visited);
        
        
        return ans;   
    }
    
    void dfs(TreeNode* cur , int k , vector<int>&ans , unordered_map<TreeNode*, TreeNode*> &parent_track, unordered_map<TreeNode*, bool> &visited){
        if(cur==NULL){
            return;
        }
        if(k==0){
            ans.push_back(cur->val);
            return;
        }
        
        if(cur->left){
            if(!visited[cur->left]){
                visited[cur->left] = true;
                dfs(cur->left , k-1 , ans , parent_track , visited);
                
            }
        }
                
        if(cur->right){
            if(!visited[cur->right]){
                visited[cur->right] = true;
                dfs(cur->right , k-1 , ans , parent_track , visited);
                
            }
        }
        
                
        if(parent_track[cur]){
            if(!visited[parent_track[cur]]){
                visited[parent_track[cur]] = true;
                dfs(parent_track[cur] , k-1 , ans , parent_track , visited);
                
            }
        }
    }
    
};