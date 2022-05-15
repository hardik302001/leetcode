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

// https://leetcode.com/problems/deepest-leaves-sum/discuss/1152947/Deepest-Leaves-Sum-or-Short-and-Easy-Solutions-w-Explanation-or-BFS-and-DFS-Approach



class Solution {
public:
  int deepestLeavesSum(TreeNode* root) {

	int sum = 0, n;

	queue<TreeNode*> q; // required for level-order traversal

	q.push(root);

	while(!q.empty()){

		sum = 0, n = size(q); // reset sum when deeper level is reached and accumulate for that level

		for(int i = 0; i < n; i++){

			auto top = q.front(); q.pop();

			sum += top -> val;     

			if(top -> left) q.push(top -> left);

			if(top -> right) q.push(top -> right);

		}                

	}

	return sum; // final value held by 'sum' will be sum of values of nodes at the deepest level

}
        
    
};