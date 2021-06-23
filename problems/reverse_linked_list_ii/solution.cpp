//  https://www.geeksforgeeks.org/reverse-sublist-linked-list/


class Solution {
public:

	ListNode* reverse(ListNode* head) {
		ListNode* p = NULL;
		ListNode* n;
		ListNode* c = head;
		while(c){
			n= c->next;
			c->next = p;
			p = c;
			 c=n;
		}
		head = p;
		return head;
	}

	ListNode* reverseBetween(ListNode* head, int m, int n) {

		if(m == n) return head;

		ListNode* rev = NULL, *rev_prev = NULL;
		ListNode* revend = NULL, *revend_next = NULL;

		ListNode* curr = head;
		int i=1;

		while(curr && i <= n){
			if(i<m) rev_prev = curr;
			if(i==m) rev = curr;
			if(i == n){
				revend = curr;
				revend_next = curr->next;
			}
			curr = curr->next;
			i++;
		}

		revend->next = NULL;

		revend = reverse(rev);

		if(rev_prev){                    //we needed to take 2 cases bcz
			rev_prev->next = revend;
		}else{                           //here rev_prev was NULL, so we cant declare rev_prev->next...
			head = revend;
		}

		rev->next = revend_next;
		return head;
	}
};