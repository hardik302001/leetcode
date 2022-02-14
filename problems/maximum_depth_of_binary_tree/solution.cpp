/*
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int lh = 1 + maxDepth(root->left);
        int rh = 1 + maxDepth(root->right);
        return max(lh, rh);
    }
};
*/
/*
Although the time complexity is same as O(n), but the space complexities are different.
the DFS is O(logN) while the BFS is O(N), the reason is that for a balanced binary search tree, the last row of leaves is equal to half of the total node number.
*/


class Solution {
public:
    int maxDepth(TreeNode *root)
    {
        if(root == NULL)
            return 0;

        int res = 0;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            for(int i = 0, n = q.size(); i < n; ++ i)
            {
                TreeNode *p = q.front();
                q.pop();

                if(p -> left != NULL)
                    q.push(p -> left);
                if(p -> right != NULL)
                    q.push(p -> right);
            }
            res++;
        }

        return res;
    }
};