// also see: https://leetcode.com/problems/intersection-of-two-linked-lists/




/*
see below code ..that show use of hashmap in linklist quetsions!
this is approach 2 that is having space compelxtiy O(1)
approach 1 in comment below using hash map

Step 1: Determine whether there is a cycle

1.1) Using a slow pointer that move forward 1 step each time

1.2) Using a fast pointer that move forward 2 steps each time

1.3) If the slow pointer and fast pointer both point to the same location after several moving steps, there is a cycle;

1.4) Otherwise, if (fast->next == NULL || fast->next->next == NULL), there has no cycle.




Step 2: If there is a cycle, whenever u get slow and fast pointer equal, it means there is cycle..but we need the entry point of cycle..so as slow==fast,make a entry pointer from head...and move entry and slow pointer simulateneously..where they meet is entry point of cycle..




return the entry location of the cycle


// ---------------------------------------------------------------------------------------

PROOF:


https://leetcode.com/problems/linked-list-cycle-ii/discuss/44781/Concise-O(n)-solution-by-using-C++-with-Detailed-Alogrithm-Description/739544

To understand this solution, you just need to ask yourself this question.
Assume the distance from head to the start of the loop is x1
the distance from the start of the loop to the point fast and slow meet is x2
the distance from the point fast and slow meet to the start of the loop is x3

What is the distance fast moved? What is the distance slow moved? And their relationship?

x1 + x2 + x3 + x2
x1 + x2
x1 + x2 + x3 + x2 = 2 (x1 + x2)
Q: Why x1 + x2 + x3 + x2 = 2 (x1 + x2)?

Ans: Its just the relationship between the distance travelled by fast ptr and the distance travelled by the slow ptr.
As fast ptr, runs twice the speed of slow ptr. Therefore, when they meet, distance travelled by fast ptr will be 2*(distance travelled by slow ptr).

Therefore, x1 = x3.




It can be concluded that the distance between the head location and entry location is equal to the distance between the meeting location and the entry location along the direction of forward movement.

So, when the slow pointer and the fast pointer encounter in the cycle, we can define a pointer "entry" that point to the head, this "entry" pointer moves one step each time so as the slow pointer. When this "entry" pointer and the slow pointer both point to the same location, this location is the node where the cycle begins.

==========================================================================================

Here is the code:
*/
class Solution{
public:

ListNode *detectCycle(ListNode *head) {
    if (head == NULL || head->next == NULL)
        return NULL;
    
    ListNode *slow  = head;
    ListNode *fast  = head;
    ListNode *entry = head;
    
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {                      // there is a cycle
            while(slow != entry) {               // found the entry location, very impo step
                slow  = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return NULL;                                 // there has no cycle
}
    
};


/*
//HASHMAP OF { LINKLIST AND INDEX } brute approach bcz extra O(n) space
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
     
        if(!head)
            return NULL;
        
        map<ListNode*,int>m;
        
        ListNode* temp=head;
        int i=0;
        
        while(temp!=NULL)
        {
            auto id=m.find(temp);
            if(id==m.end())
                m.insert({temp,i});
            else
                return id->first;  // we were having pointer to class, so we used arrow operator
            ++i;
            
            temp=temp->next;
        }
        
        return NULL;
    
    }
};
*/