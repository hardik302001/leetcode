
class Solution {
public:
  
      void traverseAllNodes(TreeNode *root, set<int> &s)
      {
        if (root)
        {
          s.insert(root->val);
          traverseAllNodes(root->left, s);
          traverseAllNodes(root->right, s);
        }
      }

      int findSecondMinimumValue(TreeNode *root)
      {
        set<int> s;              //automatically sorted
        traverseAllNodes(root, s);
        return s.size() < 2 ? -1 : *std::next(s.begin());   //set is unsubscriptable, so we will use iterator
      }
};
