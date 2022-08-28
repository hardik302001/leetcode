// courtesy : https://www.youtube.com/watch?v=LnHSOy7ctms



// MUST READ, SOME POINTS TO TAKE CARE OF

/*
1. We usually say that we cant make binary tree from preorder and postorder... 
2. Actually we can , but that may or may not be not be UNIQUE.
3. If we have skew tree, then its preorder and postorder will be same, and we can have left skew and right skew tree possible. So , it isnt unique... right.

4. Here , we focus on child of root , to partition.
5. Very important to pass Idx by reference, it take care of value of Idx, in right child exploration , when we return node, when left==right

*/


// also see: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// also see: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/


// TC: o(n)

class Solution {
public:
    
    unordered_map<int, int>m;
    TreeNode* helper(vector<int>& preorder, vector<int>& postorder, int& Idx, int left, int right) {   // pass by reference
        if (left > right) return NULL;
        
        TreeNode* newNode = new TreeNode(preorder[Idx]);
        Idx++;                   // very important to update Idx, so now we will partition on basis of child (left child)
      
        if(left==right)          // very important. Usually we dont do it in LC 105 and LC 106
            return newNode;
        
        int pivot = m[preorder[Idx]];  
        
        newNode->left  = helper(preorder, postorder, Idx, left, pivot);
        newNode->right = helper(preorder, postorder, Idx, pivot+1, right-1);     // right - 1, bcz it will be root
        
        return newNode;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        int Idx = 0;
        for(int i = 0;i<n;i++){
            m[postorder[i]] = i;
        }
        return helper(preorder, postorder, Idx , 0 , n-1);
    }
};




// ---------------------------------------------------------------------------------------
// TC: o(n^2)
/*
class Solution {
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& postorder, int& Idx, int left, int right) {   // pass by reference
        if (left > right) return NULL;
        
        TreeNode* newNode = new TreeNode(preorder[Idx]);
        Idx++;                   // very important to update Idx, so now we will partition on basis of child (left child)
      
        if(left==right)          // very important. Usually we dont do it in LC 105 and LC 106
            return newNode;
        
        int pivot = left;  
        
        while(postorder[pivot] != preorder[Idx]) pivot++;   
        
        newNode->left  = helper(preorder, postorder, Idx, left, pivot);
        newNode->right = helper(preorder, postorder, Idx, pivot+1, right-1);     // right - 1, bcz it will be root
        
        return newNode;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        int Idx = 0;
        return helper(preorder, postorder, Idx , 0 , n-1);
    }
};
*/