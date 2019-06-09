/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

&Title
82. Remove Duplicates from Sorted List II

&Question
Given a sorted linked list, delete all nodes that 
have duplicate numbers, leaving only distinct numb
ers from the original list.
Example 1:
Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:
Input: 1->1->1->2->3
Output: 2->3

*/


/*
#include "header.h"

struct ListNode {
	int val;
    ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
		ListNode* front = new ListNode(-1);
		bool duplicate = false;
		front->next = head;
		head = front;
		ListNode* temp = head->next, *prev = head;
		int val = -2;
		while (temp) {
			val = temp->val;
			temp = temp->next;
			while (temp && temp->val == val) {
				temp = temp->next;
				duplicate = true;
			}
			if (duplicate) {
				prev->next = temp;
				duplicate = false;
			}
			else {
				prev = prev->next;
			}
		}
		
		head = head->next;
		return head;
    }
};

int main() {
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = new ListNode(3);
	head->next->next->next->next->next = new ListNode(4);
	head->next->next->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next->next->next = new ListNode(6);
	head->next->next->next->next->next->next->next->next = new ListNode(6);
	head = Solution().deleteDuplicates(head);
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
}
*/

/*



c++
b의 다음이랑 e를 비교하면 중복된건지 아닌건지 확인 되는구나...
내 소스랑 원리는 같은디 훨 깔끔하다잉 빠르구..
```
class Solution {
public:
	  ListNode* deleteDuplicates(ListNode* head) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* b = dummy, *e = head;
		while(nullptr != e) {
			while(e->next != nullptr && e->val == e->next->val) e = e->next;
			if(b->next != e) {
				b->next = e->next;
			} else {
				b = b->next;
			}
			e = e->next;
		}
		return dummy->next;
	}
};
```
*/