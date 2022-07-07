/*
Concept : Perform a level order traversal using Queue and for each level of the tree keep track of the maximum value of that level.
Once that level is completed, push the last known value to the vector answer
*/

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> answer;
        queue<TreeNode*> q;
        if(!root) return answer;
        q.push(root);
        while(!q.empty())
        {
            const int size = q.size();
            int maxi = INT_MIN;
            for(int i = 0; i < size; i++)
            {
                auto curr = q.front();
                q.pop();
                maxi = max(maxi, curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            answer.push_back(maxi);
        }
        return answer;
    }
};