

// backtracking
/*
Time: O(N^2), where N <= 5000 is the number of elements in the binary tree.

First, we think the time complexity is O(N) because we only visit each node once.
But we forgot to calculate the cost to copy the current path when we found a valid path, which in the worst case can cost O(N^2), let see the following example for more clear.

space : O(h)
*/
class Solution {
public:
    vector<vector<int>>ans;
    
    void recur(TreeNode* root, vector<int>&cur, int target){
        if(root==NULL) return ;
        cur.push_back(root->val);
        target-= root->val;
        if(root->left ==NULL and root->right==NULL){   // now i m not leaf node, and only left with leaf node value
            if(target==0){             // conisder the leaf node value
                ans.push_back(cur);
            }
            // we wont return here bcz we have added current node, and we need to pop it also , bcz else it will forever
        }
        
    
        recur(root->left, cur,  target);
        recur(root->right, cur, target);
        cur.pop_back();
        target += root->val;
        
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int>cur;
        recur(root, cur, target);
        return ans;
    }
};