// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/discuss/728353/C%2B%2B-or-Two-Solutions



/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/


//WE ARE DOING DFS ONLY...traverse...if you get child..start traversing that child first..traverse child sequence first, then continue with original sequence,...and so on..
class Solution {
public:
    // Helper method to insert node in array - iteration
    void TravNodes(Node* head, vector<Node*>& ans){
        ans.push_back(head);   // Insert the current node
		 // if node has a child recursive call to the child
        if(head->child) TravNodes(head->child,ans);  
        if(!head->next) return;  // if next node is NULL return
        TravNodes(head->next,ans);  // Traverse the next node
    }
    
    Node* flatten(Node* head) {
        if(!head) return head;  // If there is node head return
        vector<Node*>ans;  // ans array to store nodes in order
        ans.push_back(NULL); // Let the first element be NULL as head->prev = NULL;
        TravNodes(head,ans);  // Helper function call
		// Iterate from the second element till second last element (1st ele is NULL)
        
        //JOIN THE NODES!
        for(int i = 1;i<ans.size()-1;i++){ 
            ans[i]->prev = ans[i-1];   // set prev ele
            ans[i]->next = ans[i+1];  // set next ele
            ans[i]->child = nullptr;  // remove child ptr
        }
        
		// Set next and prev for last element
        ans[ans.size()-1]->prev = ans[ans.size()-2];  
        ans[ans.size()-1]->next = NULL;
        ans[ans.size()-1]->child = NULL;
        return ans[1];  // Return the head stored in ans[1]
    }
};