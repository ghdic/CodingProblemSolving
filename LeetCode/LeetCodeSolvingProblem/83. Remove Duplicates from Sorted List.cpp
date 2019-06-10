/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list/

&Title
83. Remove Duplicates from Sorted List

&Question
Given a sorted linked list, delete all duplicates 
such that each element appear only once.
Example 1:
Input: 1->1->2
Output: 1->2
Example 2:
Input: 1->1->2->3->3
Output: 1->2->3

*/

/*
#include "header.h"

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
		if (!head)return head;
		ListNode* temp = head, *prev = head;
		while (temp->next) {
			temp = temp->next;
			if (prev->val != temp->val) {
				prev->next = temp;
				prev = temp;
			}
		}
		prev->next = NULL;
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