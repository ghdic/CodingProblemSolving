/*
https://leetcode.com/problems/add-two-numbers/

&Title
2. Add Two Numbers

&Question
You are given two non-empty linked lists represent
ing two non-negative integers. The digits are stor
ed in reverse order and each of their nodes contai
n a single digit. Add the two numbers and return i
t as a linked list.
You may assume the two numbers do not contain any 
leading zero, except the number 0 itself.
Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/





/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
#include "header.h"
// 코드 제출시 struct부분은 넣지 않음 redefine에러뜸
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class TempList { // 리스트 단순하게 구현
public:
	ListNode* head = NULL;

	ListNode* push(int item) {
		ListNode* temp = head;
		if (temp == NULL) {
			head = new ListNode(item);
			return head;
		}
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new ListNode(item);
		return head;
	}

	

};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		TempList tmlist;
		ListNode *temp1 = l1, *temp2 = l2;
		bool up = false;
		int item1, item2, val;
		while (temp1 != NULL && temp2 != NULL) { // 둘중 하나가 빌때까지 돌림
			item1 = temp1->val;
			item2 = temp2->val;
			temp1 = temp1->next;
			temp2 = temp2->next;

			if (up == true) {
				val = item1 + item2 + 1;
				if (val / 10 == 0) {
					tmlist.push(val);
					up = false;
				}
				else {
					tmlist.push(val % 10);
					up = true;
				}
			}
			else {
				val = item1 + item2;
				if (val / 10 == 0) {
					tmlist.push(val);
					up = false;
				}
				else {
					tmlist.push(val % 10);
					up = true;
				}
			}
		}

		while (temp1 != NULL) { // 남은것도 빌때까지 돌려줌
			item1 = temp1->val;
			temp1 = temp1->next;
			if (up == true) {
				val = item1 + 1;
				if (val / 10 == 0) {
					tmlist.push(val);
					up = false;
				}
				else {
					tmlist.push(val % 10);
					up = true;
				}
			}
			else {
				val = item1;
				tmlist.push(val);
			}
		}
		while (temp2 != NULL) {
			item2 = temp2->val;
			temp2 = temp2->next;
			if (up == true) {
				val = item2 + 1;
				if (val / 10 == 0) {
					tmlist.push(val);
					up = false;
				}
				else {
					tmlist.push(val % 10);
					up = true;
				}
			}
			else {
				val = item2;
				tmlist.push(val);
			}
		}
		if (up == true) { // 양쪽다 비었는데 올림수가 남은 경우의 처리 이것때매 한번 틀림 ㅜㅠ
			val = 1;
			tmlist.push(val);
			up = false;
		}
		return tmlist.head;
    }
};

int main() {
	Solution solution;
	TempList l1, l2;
	ListNode* temp;
	l1.push(2);
	l1.push(4);
	l1.push(3);
	l2.push(5);
	l2.push(6);
	l2.push(4);

	temp = solution.addTwoNumbers(l1.head, l2.head);
	while (temp != NULL) {
		cout << temp->val;
		temp = temp->next;
	}
	cout << endl; // 출력값을 거꾸로 값을 해보면 올바른답
}
*/

/*
Solution

Java Code
기본적으로 하는방식은 나랑 같다. 하지만 코드가 더 간결하고 깔끔하게 짜여있다.

1. head 노드를 NULL값으로 초기합니다.
2. carry(올림)을 0으로 초기화 합니다.
3. p와 q를 l1, l2로 초기화 합니다.
4. l1, l2가 둘다 NULL값을 반환할때까지 루프를 돌립니다.
	* x를 p의 노드의 value로, y를 q의 노드의 value로 설정한다.
	  만약 이미 노드의 마지막이라면 0으로 설정한다.
	* sum = x + y + carry로 설정한다.
	* carry = sum/10으로 설정한다.
	* 새로운 노드를 생성해 sum값을 집어 넣어 nextNode에 넣어준다.
	* p, q노드를 진척시킨다.
5. carry = 1 이 남았는지 확인하고 남을경우 1을 새로운 노드를 생성하여 넣어준다.
6. head Node를 return 한다.

```
public ListNode addTwoNumbers(ListNode l1, ListNode l2){
	ListNode dummyHead = new ListNode(0);
	ListNode p = l1, q = l2, curr = dummyHead;
	int carry = 0;
	while(p!=null || q!=null){
		int x = (p!=null) ? p.val : 0;
		int y = (q!=null) ? q.val : 0;
		int sum = carry + x + y;
		carry = sum / 10;
		curr.next = new ListNode(sum % 10);
		curr = curr.next;
		if(p!=null)p=p.next;
		if(q!=null)q=q.next;
	}
	if(carry > 0) {
		curr.next = new ListNode(carry);
	}
	return dummyHead.next;
}
```
*/