/*
https://leetcode.com/problems/reverse-nodes-in-k-group/

&Title
25. Reverse Nodes in k-Group

&Question
Given a linked list, reverse the nodes of a linked
 list k at a time and return its modified list.
k is a positive integer and is less than or equal 
to the length of the linked list. If the number of
 nodes is not a multiple of k then left-out nodes 
in the end should remain as it is.
Example:
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
Note:
Only constant extra memory is allowed.
You may not alter the values in the list's nodes, 
only nodes itself may be changed.

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
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k == 0 || k == 1 || !head) return head;

		ListNode* findN = head, *start = head, *end = head, *nextNode, *prevNode = head, *tempNode;
		bool check = false;
		while (true) {
			for (int i = 0; i < k; i++) {
				if (!findN) {
					check = true;
					break;
				}
				findN = findN->next;
			}
			if (!check) {
				nextNode = end->next;
				tempNode = start;
				start->next = findN;
				for (int j = 0; j < k - 1; j++) {
					end = nextNode;
					nextNode = end->next;
					end->next = start;
					start = end;
				}
				if (prevNode == head) {
					head = end;
				}
				else
					prevNode->next = end;
				prevNode = tempNode;
				start = findN;
				end = findN;
			}
			else
				break;
		}
		return head;
    }
};

void PrintNode(ListNode * head) {
	if (head == NULL)
		return;
	cout << head->val << " ";
	PrintNode(head->next);

}

int main() {
	ListNode* head;
	int k = 3;
	head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head = Solution().reverseKGroup(head, 4);
	PrintNode(head);
	return 0;
}
*/

/*
&Solution
추가적으로 노드 생성안하고 풀었음 N만큼의 범위의 노드를
각각 반대 방향 노드를 가르키게끔 함
*/