// approach 1
// idea similar to : https://leetcode.com/problems/validate-binary-search-tree/

/*
class Solution {
public:

    void closest(TreeNode* root, int data, int &ans1 , int &ans2)
    {
        if(!root) return;

        if(root->val<data)
        {
            ans1 = root->val;
            closest(root->right,data,ans1,ans2);
        }
        else if(root->val>data)
        {
            ans2 = root->val;
            closest(root->left,data,ans1,ans2);
        }
        else 
        {
            ans1 = root->val;
            ans2 = root->val;
            return;
        }

    }



    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {

        vector<vector<int>> res;

        for(int i = 0; i< queries.size();i++)
        {
            vector<int> ans;
            ans.push_back(INT_MIN);
            ans.push_back(INT_MAX);
            closest(root,queries[i],ans[0],ans[1]);
            ans[0] = (ans[0]==INT_MIN)?-1:ans[0];
            ans[1] = (ans[1] == INT_MAX)?-1:ans[1];
            res.push_back(ans);
        }

        return res;
    
    }
};

*/
// -----------------------------------------------------------------
// approach 2: 


/*
INORDER + BS
Approach is to get the sorted list by traversing each node using inorder-traversal.
Then take lower bound and upper bound of each querries to get min and max.
// *************************************************************************************************************
lower_bound returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘val’. 
and if the value is not present in the vector then it returns the end iterator.
upper_bound returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’. 
// *************************************************************************************************************
Note: 
There are few conditions that need to be taken care while taking lower and upper bound:
1. when the lower bound index is more than array size -> just take the index of last element
2. when lower bound value is not present in the array -> take just previous value.
3. when upper bound value is evaluated and may be previous value is equal with query -> check and if require take previous index value.
 
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& nums){
        if(root){
            inorder(root->left, nums);
            nums.push_back(root->val);
            inorder(root->right, nums);
        }
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> vals;
        inorder(root, vals);
        int n = queries.size();
        vector<vector<int>> ret(n);
        for (int i=0; i<n; i++) {
            auto it = lower_bound(vals.begin(), vals.end(), queries[i]);
            int mx = it == vals.end() ? -1 : *it;
            it = upper_bound(vals.begin(), vals.end(), queries[i]);
            int mn = it == vals.begin() ? -1 : *prev(it);
            ret[i] = {mn, mx};
        }
        return ret;
    }
};