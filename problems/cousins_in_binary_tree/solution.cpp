
//LEVEL ORDER TRAVERSAL
//it is most optimised...it stops whenever we get answer, no need to traverse extra nodes..
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        
		//if one of the values equals the value of the root then we have no cousins
        if(root == NULL || root->val == x || root->val == y){
            return false;
        }
		
        queue<pair<int, TreeNode*>> toVisite;
        toVisite.push(make_pair(0,root));
        int levelCount = 1;
        int count = 0;
		TreeNode* node ; 
        int xParent = 0, yParent = 0;
		
        while(!toVisite.empty()){
		
            while(levelCount --){          //all nodes of same level
			
                node = toVisite.front().second;
                if(node->val == x){
                    xParent = toVisite.front().first;
                }
                if(node->val == y){
                    yParent = toVisite.front().first;
                }
                if(yParent && xParent && yParent != xParent){
                    return true;
                }
                
                toVisite.pop(); 
                if(node->left != NULL){
                    count ++; 
                    toVisite.push(make_pair(node->val, node->left)); 
                }
                if(node->right != NULL){
                    count ++; 
                    toVisite.push(make_pair(node->val, node->right)); 
                }
            }
            
            levelCount = count; 
            count = 0; 
            yParent = 0, xParent = 0; // fresh start for new level...
        }
        return false;
    }
};





//recursive: idea is same, just we are keepjng track of what we need that is x and y only here

//O(1)  space
//O(N)  time
/*
class Solution {
public:

int xdepth, ydepth, xparent, yparent;

void depth(TreeNode* root, int x, int y, int dep, int par_val){
    if(root==NULL) return;
    if(root->val==x){
        xdepth=dep;
        xparent=par_val;
        return;
    }
    if(root->val==y){
        ydepth=dep;
        yparent=par_val;
        return;
    }
    depth(root->left, x, y, dep+1, root->val);
    depth(root->right, x, y, dep+1, root->val);
}
bool isCousins(TreeNode* root, int x, int y) {
    if(root->val==x || root->val==y) return false;
    depth(root, x, y, 0, 0);
    
    if(xdepth==ydepth && xparent!=yparent) return true;
    return false;
}

};


*/
/*
//keep track of depth and parent for each node in map..
//O(n) space
//O(n)  time

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
		unordered_map<int, pair<int, int>> m;
		helper(root, 0, -1, m);
		return m[x].first == m[y].first && m[x].second != m[y].second;
    }
    void helper(TreeNode* node, int depth, int parent, unordered_map<int, pair<int, int>>& m) {
    	if (!node) return;
    	m[node->val] = {depth, parent};
    	helper(node->left, depth + 1, node->val, m);
    	helper(node->right, depth + 1, node->val, m);
    }
};


*/


