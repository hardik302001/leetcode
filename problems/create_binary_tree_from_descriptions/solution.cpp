// ROOT = INDEGREE = 0

// https://leetcode.com/problems/create-binary-tree-from-descriptions/discuss/1823728/Do-as-question-says-oror-Easy-and-well-explained-oror-Clean-Code





class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // To store whether we have already created a subtree with give node as key
        unordered_map<int,TreeNode*> created;
        
        // It will help to find the root node
        vector<int> inDegree(100001,0);
        for(auto &d:descriptions) {
            // If already created than get the older once else create new
            TreeNode *parent = created.find(d[0])==created.end() ? new TreeNode(d[0]): created[d[0]];
            TreeNode *child = created.find(d[1])==created.end() ? new TreeNode(d[1]): created[d[1]];
            
            // Do as problem description said
            if(d[2]) {
                parent->left = child;
            } else {
                parent->right = child;
            }
            
            // Store back to use for future
            created[d[0]] = parent;
            created[d[1]] = child;
            inDegree[d[1]]++;
        }
        
        // Find the root node
        for(auto &[key, node]:created) {
            if(inDegree[key] == 0) {
                return node;
            }
        }
        return nullptr;
    }
};