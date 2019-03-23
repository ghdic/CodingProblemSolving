/*
https://leetcode.com/problems/merge-k-sorted-lists/

&Title
23. Merge k Sorted Lists

&Question
Merge k sorted linked lists and return it as one s
orted list. Analyze and describe its complexity.
Example:
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

*/

/*
#include "header.h"

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

struct CustomCompare
{
	bool operator()(const ListNode* lhs, const ListNode* rhs)
	{
		return lhs->val > rhs->val;
	}
};
class Solution {
public:
	
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* result = NULL, *lastNode = NULL;
		priority_queue<ListNode*, vector<ListNode*>, CustomCompare> pq;
		for (int i = 0; i < lists.size(); i++) {
			if (lists[i] != NULL) {
				pq.push(lists[i]);
			}
		}
		while (!pq.empty()) {
			if (result == NULL) {
				result = pq.top();
				lastNode = pq.top();
			}
			else {
				lastNode->next = pq.top();
				lastNode = pq.top();
			}
			ListNode* item = pq.top()->next;
			pq.pop();
			if (item != NULL)
				pq.push(item);
			lastNode->next = NULL;
		}
		return result;
    }
};

void PrintNode(ListNode * head) {
	if (head == NULL)
		return;
	cout << head->val << " ";
	PrintNode(head->next);
	
}

int main() {
	vector<ListNode*> lists;
	ListNode *a1, *a2, *a3;
	a1 = new ListNode(3);
	a1->next = new ListNode(4);
	a1->next->next = new ListNode(5);

	a2 = new ListNode(1);
	a2->next = new ListNode(3);
	a2->next->next = new ListNode(4);

	a3 = new ListNode(2);
	a3->next = new ListNode(7);
	a3->next->next = new ListNode(8);

	lists.push_back(a1);
	lists.push_back(a2);
	lists.push_back(a3);

	a1 = Solution().mergeKLists(lists);
	PrintNode(a1);

	return 0;
}
*/

/*
&Solution
매번 sort한다음 맨 앞 원소를 사용하는식으로 했는데
sort 비용이 컸었나보다. 그래서 priority_queue를 썼더니
28ms faster than 95.66%가 나왔다 훗
문제만 보면 간단하지만. 어떤식으로 접근하여 
더 빠르게 할 것인지가 핵심인 문제인 것 같다.

접근법 1: Brute Force
그냥 몽땅 합친 다음에 정렬하는 방식이다.
Python
```
class Solution(object):
	def mergeKLists(self, lists):
		self.nodes = []
		head = point = ListNode(0)
		for l in lists:
			while l:
				self.nodes.append(l.val)
				l = l.next
		for x in sorted(self.nodes):
			point.next = ListNode(x)
			point = point.next
		return head.next
```
시간복잡도 : O(N log N)


접근법 2: 하나씩 비교하기
맨처음 내가 접근했던 방식이다. 그런데 제일 작은걸 찾기보단
정렬을 사용해서 제일 작은걸 찾기에 비용이 너무 컸었다.

시간복잡도 : O(kN)


접근법 3: 접근법2를 활용한 Priority Queue사용
내가 푼 방식으로 접근법2 + priority Queue를 사용한다
priority Queue는 heap을 구현한 방식으로 이진트리에서
root를 pop하면 그 다음으로 정렬기준에 따른 item이 root로 온다.
따라서 정렬에 대한 비용이 엄청 나게 줄어든다. 대신 item을 추가할때
다른 것에 비해 비용이 조금 더 든다.

Python
```
from queue import PriorityQueue

class Solution(object):
	def mergeKLists(self, lists):

		head = point = ListNode(0)
		q = PriorityQueue()
		for i in lists:
			if l:
				q.put((l.val, l))
		while not q.empty():
			val, node = q.get()
			point.next = ListNode(val)
			point = point.next
			node = node.nnext
			if node:
				q.put((node.val, node))
			return head.next
```
시간복잡도 : O(Nlogk)


접근법 4: Merge lists one by one
Merge 정렬을 이용해서 푸는 방식이다.
접근법1이 전부 합친 후 정렬이였다면
접근법4는 맨 앞에 두개의 리스트를 짝지어서 정렬하여
한개의 리스트가 남을때까지 합병한다.
총 n-1번을 반복한다.

시간복잡도 : O(kN)


접근법 5: Merge with Divide And Conquer
접근법4의 응용이자 합병정렬(merge sort)의 응용이다.
앞에 리스트만 짝지어서 정렬할 경우
맨 앞에 있는 리스트의 크기가 너무 커지기 때문에
비교하는 비용이 커지게 된다.
따라서 두개씩 짝지어서 정렬하는 방식이다.

python
```
class Solution(object):
	def mergeKLists(self, lists):
		amount = len(lists)
		interval = 1
		while interval < amount:
			for i in range(0, amount - interval, interval * 2):
				lists[i] = self.merge2Lists(lists[i], lsts[i + interval]):
				interval *= 2
		return lists[0] if amount > 0 else lists

	def merge2Lists(self, l1, l2):
		head = point = ListNode(0)
		while l1 and l2:
			if l1.val <= l2.val:
				point.next = l1
				l1 = l1.next
			else:
				point.next = l2
				l2 = l1
				l1 = point.next.next
			point = point.next
		if not l1:
			point.next = l2
		else:
			point.next = l1
		return head.next

```
시간복잡도 : O(Nlogk)
*/