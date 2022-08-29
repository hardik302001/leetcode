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
    unordered_map<int, int>m;
    
    vector<int>ans;
    int recur(TreeNode* root ){
        if(root==NULL) return 0;

        int s1 = recur(root->left);
        int s2 = recur(root->right);
        int s = s1 + s2 + root->val;
        m[s]++;

        return s;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root==NULL)  return ans;

        recur(root);
        int ma = INT_MIN;
        for(auto p: m){
            ma = max(ma , p.second); 
        }

        for(auto p:m){
            if(p.second==ma){
                ans.push_back(p.first);
            }
        }
        return ans;

    
    }
};