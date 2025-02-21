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
// �ڵ� ����� struct�κ��� ���� ���� redefine������
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class TempList { // ����Ʈ �ܼ��ϰ� ����
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
		while (temp1 != NULL && temp2 != NULL) { // ���� �ϳ��� �������� ����
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

		while (temp1 != NULL) { // �����͵� �������� ������
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
		if (up == true) { // ���ʴ� ����µ� �ø����� ���� ����� ó�� �̰Ͷ��� �ѹ� Ʋ�� �̤�
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
	cout << endl; // ��°��� �Ųٷ� ���� �غ��� �ùٸ���
}
*/

/*
Solution

Java Code
�⺻������ �ϴ¹���� ���� ����. ������ �ڵ尡 �� �����ϰ� ����ϰ� ¥���ִ�.

1. head ��带 NULL������ �ʱ��մϴ�.
2. carry(�ø�)�� 0���� �ʱ�ȭ �մϴ�.
3. p�� q�� l1, l2�� �ʱ�ȭ �մϴ�.
4. l1, l2�� �Ѵ� NULL���� ��ȯ�Ҷ����� ������ �����ϴ�.
	* x�� p�� ����� value��, y�� q�� ����� value�� �����Ѵ�.
	  ���� �̹� ����� �������̶�� 0���� �����Ѵ�.
	* sum = x + y + carry�� �����Ѵ�.
	* carry = sum/10���� �����Ѵ�.
	* ���ο� ��带 ������ sum���� ���� �־� nextNode�� �־��ش�.
	* p, q��带 ��ô��Ų��.
5. carry = 1 �� ���Ҵ��� Ȯ���ϰ� ������� 1�� ���ο� ��带 �����Ͽ� �־��ش�.
6. head Node�� return �Ѵ�.

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

