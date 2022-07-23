// O(n)
// idea is similar to LEETCODE: subarray sum equals k
// we are visiting every node once

// https://leetcode.com/problems/path-sum-iii/discuss/91908/C%2B%2B-solution-with-prefix-sum-stored-in-hash-table

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<long long int, int> m;
        m[0]++;
        
        int total = 0;
        helper(root, 0, sum, total, m);
        return total;
    }
    
    void helper(TreeNode *p, long long int cur, int sum, int &total, unordered_map<long long int, int> &m) {
        if (!p) return;
        
        cur += p->val;
        if (m.find(cur - sum) != m.end()) total += m[cur - sum];
        m[cur]++;
        
        helper(p->left, cur, sum, total, m);
        helper(p->right, cur, sum, total, m);
        
        m[cur]--;            // kind of backtracking
    }
};