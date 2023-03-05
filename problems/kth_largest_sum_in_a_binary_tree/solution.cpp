/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>s;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            int sz = q.size();
            long long cur = 0;
            while(sz--){
                TreeNode* topa = q.front();
                q.pop();
                cur += topa->val;
                if(topa->left) q.push(topa->left);
                if(topa->right) q.push(topa->right);
            }
            s.push_back(cur);
        }
        
        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());
        return int(s.size())>=k?s[k-1]:-1;
    }
};