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
   void solve(TreeNode* root, unordered_map<int,int>&mp, int &ans){
        
        if(!root) return;
        
        mp[root->val]++;                     //updating occurence of an element
        
        if(!root->left && !root->right){     //when we reached leaf node
            int c=0;                         //then we will count the number of elements whose occurence is odd
            for(auto it:mp){                 //if count of such elements is <=1, then we update ans
                if(it.second%2!=0) c++;      //For eg, 2->3->3 is a path so in map, occurences of 2=1 and 3=2
            }                                //In order to obatain a palindrome, there should be a single element present whose count of occurences is odd
            if(c<=1) ans++;                  //Hence, 2->3->3 is a plaindrome since it can be arranged to 3->2->3
        }
        
        solve(root->left,mp,ans);            //calling recursion of left and right subtree resp
        solve(root->right,mp,ans);
        
        mp[root->val]--;                     //backtrack, removing occurence of an element
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        
        unordered_map<int,int> mp;           //key=element, value=occurence
        int ans=0;
        solve(root,mp,ans);
        return ans;
    }
};