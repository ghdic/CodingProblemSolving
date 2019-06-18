/*
https://leetcode.com/problems/partition-list/

&Title
86. Partition List

&Question
Given a linked list and a value x, partition it su
ch that all nodes less than x come before nodes gr
eater than or equal to x.
You should preserve the original relative order of
 the nodes in each of the two partitions.
Example:
Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5

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
    ListNode* partition(ListNode* head, int x) {
		ListNode* temp = head, * less = new ListNode(-1), * more = new ListNode(-1), * tmore = more;
		head = less;
		while (temp) {
			if (temp->val >= x) {
				tmore->next = temp;
				tmore = tmore->next;
			}
			else {
				less->next = temp;
				less = less->next;
			}
			temp = temp->next;
		}
		less->next = more->next;
		head = head->next;
		tmore->next = NULL;
		return head;
    }
};

int main() {
	ListNode* head = new ListNode(1);
	head->next = new ListNode(4);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(2);
	int partition = 0;
	head = Solution().partition(head, partition);
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
}
*/