/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

&Title
19. Remove Nth Node From End of List

&Question
Given a linked list, remove the n-th node from the
 end of list and return its head.
Example:
Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the l
inked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Follow up:
Could you do this in one pass?

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


#include "header.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

//뒤에서 n번째꺼 삭제하는거니깐 뒤에서 n+1번째꺼 갖고있으면 되겠다
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head->next == NULL && n == 1) {
			delete head;
			head = NULL;
			return head;
		}
		ListNode* temp = head, *target = head;
		int count = 0, num = 1;
		while (temp->next != NULL) {
			if (count == n) {
				target = target->next;
			}
			else {
				count++;
			}
			temp = temp->next;
			num++;
		}
		if (num == n) {
			temp = head->next;
			delete head;
			head = temp;
		}
		else {
			temp = target->next->next;
			delete target->next;
			target->next = temp;
		}
		return head;
    }
};

int main() {
	ListNode *head = NULL, *lastNode = NULL;
	int k = 1;
	for (int i = 1; i <= 5; i++) {
		ListNode *n = new ListNode(i);
		if (head == NULL) {
			head = n;
			lastNode = n;
		}
		lastNode->next = n;
		lastNode = n;
	}
	head = new ListNode(1);
	head = Solution().removeNthFromEnd(head, k);
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	return 0;
}

/*
Solution
Approach 1: Two pass algorithm
평범한 방법으로 쭉 탐색하여 리스트의 길이를 구한 후
해당 길이의 뒤에서 n번째 값 전의 노드를 통해 뒤에서 n번째 노드를 삭제한다.

Java
```
public ListNode removeNthFromEnd(ListNode head, int n) {
	ListNode dummy = new ListNode(0);
	dummy.next = head;
	int length  = 0;
	ListNode first = head;
	while (first != null) {
		length++;
		first = first.next;
	}
	length -= n;
	first = dummy;
	while (length > 0) {
		length--;
		first = first.next;
	}
	first.next = first.next.next;
	return dummy.next;
}
```

Approach 2: One pass algorithm
내가 짠 방식이다. 근데 좀 효율적이지 못하게 짰나보다..
애 한거 보니깐 먼저 n만큼 노드 하나를 전진시키고 해버리네..
이 미리 전진시킨게 NULL이면 맨앞꺼 삭제하면 되고 나도 이렇게할껄..ㅋㅋ
암튼 n만큼 간격으로 노드 값을 갖고있으면 맨마지막 노드에 도달했을때
뒤에서 n번째 노드를 가지고 있을 수 있다.

Java
```
public ListNode removeNthFromEnd(ListNode head, int n){
	ListNode dummy = new ListNode(0);
	dummy.next = head;
	ListNode first = dummy;
	ListNode second = dummy;

	//두 모드간의 간격으로 벌린다
	for(int i = 1; i <= n + 1; i++){
		first = first.next;
	}
	//갭을 유지한채 움직인다.
	while(first != null) {
		first = first.next;
		second = second.next;
	}
	seconde.next = seconde.next.next;
	return dummy.next;
}
```
*/