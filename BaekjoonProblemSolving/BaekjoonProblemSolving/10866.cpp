/*
https://www.acmicpc.net/problem/10866

&Title
10866번 - 덱

&Question
정수를 저장하는 덱(Deque)를 구현한 다음, 입력으로 주어지는 명령을 
처리하는 프로그램을 작성하시오.명령은 총 여덟 가지이다.push_front X: 정수 X를 
덱의 앞에 넣는다.push_back X: 정수 X를 덱의 뒤에 넣는다.pop_front: 
덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 
만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.pop_back: 덱의 
가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 
덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.size: 덱에 들어있는 
정수의 개수를 출력한다.empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.front: 
덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 
정수가 없는 경우에는 -1을 출력한다.back: 덱의 가장 뒤에 있는 
정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 
출력한다. 

&Input
첫째 줄에 주어지는 명령의 수 N (1 ≤ 
N ≤ 10,000)이 주어진다. 둘쨰 줄부터 N개의 줄에는 명령이 
하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 
같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다. 

&Output
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다. 


&Example
-input
15
push_back 1
push_front 2
front
back
size
empty
pop_front
pop_back
pop_front
size
empty
pop_back
push_front 3
empty
front

-output
2
1
2
0
2
1
-1
0
1
-1
0
3


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	int N, num;
	string s;
	deque <int> deq;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (s == "push_front") {
			scanf("%d", &num);
			deq.push_front(num);
		}
		else if (s == "push_back") {
			scanf("%d", &num);
			deq.push_back(num);
		}
		else if (s == "pop_front") {
			if (deq.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", deq.front());
				deq.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (deq.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", deq.back());
				deq.pop_back();
			}
		}
		else if (s == "size") {
			printf("%d\n", deq.size());
		}
		else if (s == "empty") {
			printf("%d\n", deq.empty());
		}
		else if (s == "front") {
			if (deq.empty())printf("-1\n");
			else printf("%d\n", deq.front());
		}
		else if (s == "back") {
			if (deq.empty())printf("-1\n");
			else printf("%d\n", deq.back());
		}

	}
	return 0;
}
*/

//시간초과 ㅡㅡㅋ
/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

typedef struct deq {
	struct deq *next;
	int item;
}deq;

deq *head = NULL, *tail = NULL;

int empty() {
	if (!head)return 1;
	else return 0;
}

void push_front(int a) {
	deq *temp = new deq;
	temp->item = a;
	if (empty()) {
		head = temp;
		tail = temp;
		temp->next = NULL;
	}
	else {
		temp->next = head;
		head = temp;
	}
}

void push_back(int a) {
	deq *temp = new deq;
	temp->item = a;
	if (empty()) {
		head = temp;
		tail = temp;
		temp->next = NULL;
	}
	else {
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
	}
}

int pop_front() {
	deq *temp;
	int it;
	if (empty())return -1;
	if (head == tail) {
		temp = head;
		it = temp->item;
		head = NULL;
		tail = NULL;
	}
	else {
		temp = head;
		it = temp->item;
		head = head->next;
	}
	delete temp;
	return it;
}

int pop_back() {
	deq *temp, *hd;
	int it;
	if (empty())return -1;
	if (head == tail) {
		temp = head;
		it = temp->item;
		head = NULL;
		tail = NULL;
	}
	else {
		temp = tail;
		it = temp->item;
		hd = head;
		while (hd->next != tail) {
			hd = hd->next;
		}
		tail = hd;
	}
	delete temp;
	return it;
}

int deqSize(){
	int k = 0;
	deq * temp = head;
	while (temp) {
		temp = temp->next;
		k++;
	}
	return k;
}

int front() {
	if (empty())return -1;
	else return head->item;
}

int back() {
	if (empty())return -1;
	else return tail->item;
}
int main() {
	int N, num;
	string s;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (s == "push_front") {
			scanf("%d", &num);
			push_front(num);
		}
		else if (s == "push_back") {
			scanf("%d", &num);
			push_back(num);
		}
		else if (s == "pop_front") {
			printf("%d\n", pop_front());
		}
		else if (s == "pop_back") {
			printf("%d\n", pop_back());
		}
		else if (s == "size") {
			printf("%d\n", deqSize());
		}
		else if (s == "empty") {
			printf("%d\n", empty());
		}
		else if (s == "front") {
			printf("%d\n", front());
		}
		else if (s == "back") {
			printf("%d\n", back());
		}

	}
	return 0;
}
*/