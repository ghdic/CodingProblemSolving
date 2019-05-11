/*
https://leetcode.com/problems/rotate-list/

&Title
61. Rotate List

&Question
Given a linked list, rotate the list to the right 
by k places, where k is non-negative.
Example 1:
Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:
Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL

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
    ListNode* rotateRight(ListNode* head, int k) {
		ListNode* temp = head, * lastNode = NULL;
		if (head == NULL)return head;
		int cnt = 0;
		while (temp) {
			lastNode = temp;
			temp = temp->next;
			cnt++;
		}
		temp = head;
		k = k % cnt;
		for (int i = 0; i < cnt - k - 1; i++) {
			temp = temp->next;
		}
		lastNode->next = head;
		head = temp->next;
		temp->next = NULL;
		return head;
    }
};

int main() {
	ListNode* head = new ListNode(1);
	int k = 5;

	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head = Solution().rotateRight(head, k);
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	return 0;
}
*/

/*
이제 노드 다루는건 꽤 익숙해졌군...
*/