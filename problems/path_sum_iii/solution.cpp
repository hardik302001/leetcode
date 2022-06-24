//O(n)
//idea is similar to LEETCODE: subarray sum equals k
//we ar visiting every node once

//  https://leetcode.com/problems/path-sum-iii/discuss/91908/C%2B%2B-solution-with-prefix-sum-stored-in-hash-table


class Solution {
    unordered_map<int, int> hashMap;
    int count;
    int target;
    void find(TreeNode* root, long long int  sum) {
        if (root == 0) return;
        sum += root->val;
        int prefixSum = sum - target;
        if (hashMap.count(prefixSum)) {
            count += hashMap[prefixSum];
        }
        hashMap[sum]++;
        find(root->left, sum);
        find(root->right, sum);
        hashMap[sum]--;  // kind of backtarcking
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        count = 0;
        target = targetSum;
        hashMap[0] = 1;
        find(root, 0);
        return count;
    }
};