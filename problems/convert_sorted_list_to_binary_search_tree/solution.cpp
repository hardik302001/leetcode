// Time complexity: O(n log(n)).
// There are log(n) recursive levels because each time we split it to half, and in each level we loop through the whole list, divided into small parts.
// Space complexity: O(log(n)).
// We don't consider the returning tree as extra space, but we have log(n) recursive calls on stack.


// idea same as: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail = NULL) {
        if (head == tail)   // we need to only search till tail node,
            return NULL;
        
        ListNode* fast = head, *slow = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // find mid
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head, slow);         // head to mid
        root->right = sortedListToBST(slow->next, tail);  // mid to end
        
        return root;
    }
    
};