class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* currentNode = head;
        ListNode* lastMNode = head;
        while (currentNode != nullptr) {
            // initialize mCount to m and nCount to n
            int mCount = m, nCount = n;
            // traverse m nodes
            while (currentNode != nullptr && mCount != 0) {
                lastMNode = currentNode;
                currentNode = currentNode->next;
                mCount--;
            }
            // traverse n nodes
            while (currentNode != nullptr && nCount != 0) {
                currentNode = currentNode->next;
                nCount--;
            }
            // delete n nodes
            lastMNode->next = currentNode;
        }
        return head;    
    }
};