// Recursive Approach(C++):
// Intuition: Basically we start from Idx 0 & find preorder[Idx] from inorder, let's call it as index pivot.
// Then we create a new node with inorder[pivot] simultaneoulsy create its left child recursively and it's right child recursively and finally return the new node.
// TC= O(n^2), bcz for traversing and searching..

/*
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = inorder.size();
        int Idx = 0;             // preorder
        return helper(preorder, inorder, Idx, 0, n-1);
    }
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& Idx, int left, int right) {
        if (left > right) return NULL;
        int pivot = left;  // find the root from inorder
        
        while(inorder[pivot] != preorder[Idx]) pivot++;   
        
        Idx++;  
        
        TreeNode* newNode = new TreeNode(inorder[pivot]); 
        newNode->left = helper(preorder, inorder, Idx, left, pivot-1);
        newNode->right = helper(preorder, inorder, Idx, pivot+1, right);
        
        return newNode;
    }
};
*/



// O(n), map
// now searching in O(1)

class Solution {
public:
    unordered_map<int, int>mp;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = inorder.size();
        
        for(int i= 0;i<n;i++){
            mp[inorder[i]] = i;
        }
        
        int Idx = 0;             // preorder
        return helper(preorder, inorder, Idx, 0, n-1);
    }
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& Idx, int left, int right) {
        if (left > right) return NULL;
        int pivot = mp[preorder[Idx]];  // find the root from inorder
        
        Idx++;  
        
        TreeNode* newNode = new TreeNode(inorder[pivot]); 
        newNode->left = helper(preorder, inorder, Idx, left, pivot-1);
        newNode->right = helper(preorder, inorder, Idx, pivot+1, right);
        
        return newNode;
    }
};