/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


// see neetcode yt
class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> m;
        
        Node* ptr = head;
        while (ptr) {                      // traverse for new node and value
            m[ptr] =new Node(ptr->val);    // here ptr is address of current node
            ptr = ptr->next;
        }
        
        ptr = head;
        while (ptr) {                       // traverse and update address 
            m[ptr]->next = m[ptr->next];
            m[ptr]->random = m[ptr->random];
            ptr = ptr->next;
        }
        return m[head];
    }
};