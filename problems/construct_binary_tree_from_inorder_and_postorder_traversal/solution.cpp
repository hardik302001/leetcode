
// Recursive Approach(C++):
// Intuition: Basically we start from Idx 0 & find preorder[Idx] from inorder, let's call it as index pivot.
// Then we create a new node with inorder[pivot] simultaneoulsy create its left child recursively and it's right child recursively and finally return the new node.
// TC= O(n^2), bcz for traversing and searching..

/*
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int n = inorder.size();
        int Idx = n-1;             // postorder
        return helper(inorder, postorder, Idx, 0, n-1);
    }
    
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int& Idx, int left, int right) {
        if (left > right) return NULL;
        int pivot = left;  // find the root from inorder
        
        while(inorder[pivot] != postorder[Idx]) pivot++;   
        
        TreeNode* newNode = new TreeNode(inorder[pivot]); 
        
        Idx--;  
        //postorder, 
        newNode->right = helper(inorder, postorder, Idx, pivot+1, right);     // right      
        newNode->left = helper(inorder, postorder, Idx, left, pivot-1);       // then left

        
        return newNode;
    }
};
*/


// O(n), map
// now searching in O(1)

class Solution {
public:
    unordered_map<int, int>mp;
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int n = inorder.size();
        
        for(int i= 0;i<n;i++){
            mp[inorder[i]] = i;
        }
        
        int Idx = n-1;             // postrder
        return helper(inorder, postorder, Idx, 0, n-1);
    }
    
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int& Idx, int left, int right) {
        if (left > right) return NULL;
        int pivot = mp[postorder[Idx]];  // find the root from inorder
          
        
        TreeNode* newNode = new TreeNode(inorder[pivot]); 
        Idx--;
        
        newNode->right = helper(inorder, postorder, Idx, pivot+1, right);      // first right     
        newNode->left = helper(inorder, postorder, Idx, left, pivot-1);       // then left

        return newNode;
    }
};
